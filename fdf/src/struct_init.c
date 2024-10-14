/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 00:38:48 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/14 05:41:58 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

bool	ft_map_size_parsing(int fd, t_fdf *fdf)
{
	unsigned int	line_size;
	char			**split_lines;
	char			*line;

	fdf->map_y = 0;//sueremnt inutile car deja fait precedement, a retirer?
	fdf->map_x = 0;//initialisation a 0 par défaut avant utilisation
	while ((line = get_next_line(fd)) != NULL)//tant qu'il y a une ligne, change de ligne a chaque itération
	{
		line_size = 0;
		split_lines = ft_split(line, ' ');//splite chaque valeur pour compter combien il y en a apres
		if (!split_lines)//check si le split a échoué
			return (0);
		while (split_lines[line_size])//compte combien de valeurs
			line_size++;
		if (fdf->map_x == 0)//si premiere iteration, map_x forcement a 0
			fdf->map_x = line_size;//donnes le nb de valeur sur une ligne
		ft_free_split_lines(split_lines);//split utilise malloc, faut free avant la fin
		free(line);//GNL malloc line
		if (fdf->map_x != line_size)//si c'est pas la premiere iteration, alors la longueur de la ligne a deja ete comptée
			return (0);//retourne 0 si la ligne actuelle est differente de la premiere (toutes les lignes doivent etre les memes)
		fdf->map_y++;//augmente la taille en hauteur a chaque iteration
	}
	return (1);//la fonction s'est finie correctement
}

bool	ft_matrix_init(int fd, t_fdf *fdf)
{
	long	i_pos;//coordonnées
	long	j_value;//position ou mettre la valeur
	char	**split_lines;
	char	*line;

	fdf->matrix = (int **)malloc(sizeof(int *) * fdf->map_y);
	if (!fdf->matrix)//malloc du nombres de lignes
		return (0);
	i_pos = 0;//position 0 par defaut
	while ((line = get_next_line(fd)) != NULL)//parcours les lignes du fd
	{
		if (!(fdf->matrix[i_pos] = (int *)malloc(sizeof(int) * fdf->map_x)))//malloc a chaque iteration le nombre de valeurs sur la ligne actuelle
			return (ft_free_partial_matrix(fdf->matrix, i_pos, line), 0);
		if (!(split_lines = ft_split(line, ' ')))//split les valerus de la ligne dans un tableau a part
			return (ft_free_partial_matrix(fdf->matrix, i_pos, line), 0);
		j_value = 0;
		while (j_value < fdf->map_x)//iterer map_x fois
		{
			fdf->matrix[i_pos][j_value] = ft_atoi(split_lines[j_value]);//mettre les chaque valeur contenue dans split_lines dans la matrice
			j_value++;
		}
		ft_free_split_lines(split_lines);//libere les valeurs de la ligne  actuelle avant de passer la suivante
		free(line);//libere la ligne
		i_pos++;//passer a la position suivante pour traiter la prochaine ligne
	}
	return (1);
}

bool	ft_map_parsing(char *file, t_data *data)
{
	int	fd;

	fd = open(file, O_RDONLY);//ouvrir le fichier et verifier si il est valide, file = argv[1] (nom de la map)
	if (fd == -1)//si fd est -1, c'est que la fonction open a pas trouvé le fichier
		return (write(2, "ERROR: file could'nt be opened: \
check if file exists / if file has read rights\n", 79), 0);
	if (!ft_map_size_parsing(fd, data->fdf))//utilises GNL et split pour calculer la taille de la map (W * H)
	{
		free(data->img);
		close(fd);
		return (write(2, "ERROR: incorrect map size\n", 26), 0);
	}
	if (!ft_matrix_init(fd, data->fdf))//utilises les données precedement parsées pour creer la matrice
	{
		free(data->img);
		ft_free_matrix(data->fdf->matrix, data->fdf->map_y);
		close(fd);
		return (write(2, "ERROR: matrix init failed\n", 26), 0);
	}
	close(fd);//fermer le fd car on en a plus besoin
	return (1);
}
