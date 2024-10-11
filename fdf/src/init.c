/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:59:29 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/12 01:10:07 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

bool	ft_map_size_parsing(int fd, t_fdf *fdf_data)
{
	unsigned int	line_size;
	char			**split_lines;
	char			*line;

	line_size = 0;
	fdf_data->map_h = 0;
	while ((line = get_next_line(fd)) != NULL)//tant qu'il y a une ligne, change de ligne a chaque itération
	{
		split_lines = ft_split(line, ' ');//splite chaque valeur pour compter combien il y en a apres
		if (!split_lines)//check si le split a échoué
			return (0);
		while (split_lines[line_size])//compte combien de valeurs
			line_size++;
		if (fdf_data->map_w == 0)//si premiere iteration, map_w forcement a 0
			fdf_data->map_w = line_size;//donnes le nb de valeur sur une ligne
		else if (fdf_data->map_w != line_size)//si c'est pas la premiere iteration, alors la longueur de la ligne a deja ete comptée
			return (0);//retourne 0 si la ligne actuelle est differente de la premiere (toutes les lignes doivent etre les memes)
		fdf_data->map_h++;//augmente la taille en hauteur a chaque iteration
		ft_free_split_lines(split_lines);
		free(line);//split utilise malloc sur line, faut free avant la fin.
	}
	return (1);//la fonction s'est finie correctement
}

bool	ft_matrix_init(int fd, t_fdf *fdf_data)
{
	long	i_pos;//coordonnées
	long	j_value;//position ou mettre la valeur
	char	**split_lines;
	char	*line;

	fdf_data->matrix = (int **)malloc(sizeof(int *) * fdf_data->map_h);//malloc le nombre de lignes
	if (!fdf_data->matrix)//malloc check
		return (0);
	i_pos = 0;//position 0 par defaut
	while ((line = get_next_line(fd)) != NULL)//parcours les lignes du fd
	{
		fdf_data->matrix[i_pos] = (int *)malloc(sizeof(int) * fdf_data->map_w);//malloc a chaque iteration le nombre de valeurs sur la ligne actuelle
		if (!fdf_data->matrix[i_pos])//malloc check
			return (0);
		split_lines = ft_split(line, ' ');//split les valerus de la ligne dans un tableau a part
		if (!split_lines)//split check
			return (0);
		j_value = -1;//-1 pour ++ avant l'iteration, remet a 0 lempalcement de la valeur (pour commencer au debut de la ligne actuelle)
		while (split_lines[++j_value])//tant que je suis dans la ligne actuelle
			fdf_data->matrix[i_pos][j_value] = ft_atoi(split_lines[j_value]);//mettre les chaque valeur contenue dans split_lines dans la matrice
		ft_free_split_lines(split_lines);//libere les valeurs de la ligne  actuelle avant de passer la suivante
		free(line);//libere la ligne actuelle avant de passer la suivante
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
		close(fd);
		return (write(2, "ERROR: incorrect map size\n", 26), 0);
	}
	if (!ft_matrix_init(fd, data->fdf))//utilises les données precedement parsées pour creer la matrice
	{
		close(fd);
		return (write(2, "ERROR: matrix init failed\n", 26), 0);
	}
	close(fd);//fermer le fd car on en a plus besoin
	return (1);
}

bool	ft_mlx_init(t_data *data)
{
	data->mlx_ptr = mlx_init();//initialisation MLX et assigner le pointeur
	if (!data->mlx_ptr)//mlx check
		return (0);
	data->mlx_win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, WIN_NAME);//initialisation de la fenetre MLX
	if (!data->mlx_win_ptr)//mlx window check
	{
		mlx_destroy_display(data->mlx_ptr);//free
		free(data->mlx_ptr);
		return (0);
	}
	data->img = malloc(sizeof(t_image));//malloc des data de la future image
	if (!data->img)//malloc check
	{
		mlx_destroy_display(data->mlx_ptr);//free
		free(data->mlx_ptr);
		free(data->img);
		return (0);
	}
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);//initialisation de l'image a afficher
	data->img->img_data_ptr = mlx_get_data_addr(
			data->img->img_ptr, &data->img->img_bpp, \
			&data->img->img_line_length, &data->img->img_endian);//donne l'adresse des variables MLX
	return (1);
}

bool	ft_init_main(char *file, t_data *data)
{
	if (!ft_map_parsing(file, data))//parsing de la map dans les int, matrices, ...
		return (0);//si ft_map_parsing renvoie 0, je renvoie 0 ici aussi, ce qui renvoie un 0 au main !!!
	data->mlx_ptr = NULL;//assigner a NULL par défaut, au cas ou..
	data->mlx_win_ptr = NULL;
	data->img = NULL;
	if (!ft_mlx_init(data))//initialisation MLX
		return (0);
	return (1);
}
