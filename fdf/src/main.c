/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:05:34 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/11 23:54:33 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	terminate_program(t_data *data)
{
	long	i;

	i = -1;
	mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);//destruction image
	mlx_destroy_window(data->mlx_ptr, data->mlx_win_ptr);//destruction fenêtre
	mlx_destroy_display(data->mlx_ptr);//destruction affichage
	mlx_loop_end(data->mlx_ptr);//fin de la loop
	free(data->mlx_ptr);//free pointeur MLX
	free(data->img);//free données d'image
	while (data->fdf->matrix[++i])//boucle pour free chaque emplacement de la matrice
		free(data->fdf->matrix[i]);
	free(data->fdf->matrix);//free la matrice
	exit(0);//quitte le programme
	return (0);//inutile mais obligatoire, le fonction doit return un int..
}

int	keys_hook(int key, t_data *data)
{
	if (key == XK_Escape)//si la touche échap est appuyée, alors
		terminate_program(data);//terminer le programme proprement
	return (0);
}

int	main(int argc, char **argv)//le main du projet
{
	t_data	data;

	if (argc != 2)//un seul argument nécessaire
		return (write(2, "ERROR: too much/few arguments given.\n", 37), 1);//verifie si il y a bien un seul input (map)
	if (!ft_init_main(argv[1], &data))//fonction d'initialisation du programme
		return (1);// renvoie 1 (erreur de programme) pour arreter entierement le programme si l'initialisation échoue
	draw_fdf(&data);//algo fdf
	mlx_key_hook(data.mlx_win_ptr, keys_hook, &data);//gestion de la touche échap pour fermer le programme
	mlx_hook(data.mlx_win_ptr, 17, 0, terminate_program, &data);//hook qui terminate_program(&data) si l'event 17 (fermeture avec la croix de la window) est détecté
	mlx_loop(data.mlx_ptr);//laisse la fenetre affichée
	terminate_program(&data);//fonction pour arreter proprement le programme une fois la fenetre fermée
	return (0);//fin
}
