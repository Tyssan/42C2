/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:05:34 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/15 12:47:01 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	terminate_program(t_data *data)
{
	if (data)
	{
		if (data->mlx_ptr)
		{
			mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
			mlx_destroy_window(data->mlx_ptr, data->mlx_win_ptr);
			mlx_destroy_display(data->mlx_ptr);
			mlx_loop_end(data->mlx_ptr);
			free(data->mlx_ptr);
		}
		if (data->img)
			free(data->img);
		if (data->fdf)
		{
			ft_free_matrix(data->fdf, NULL);
			free(data->fdf);
		}
	}
	exit(0);
	return (0);
}

int	keys_hook(int key, t_data *data)
{
	if (key == XK_Escape)
		terminate_program(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (write(2, "ERROR: too much/few arguments given.\n", 37), 1);
	if (!ft_init_main(argv[1], &data))
		return (1);
	mlx_key_hook(data.mlx_win_ptr, keys_hook, &data);
	mlx_hook(data.mlx_win_ptr, 17, 0, terminate_program, &data);
	ft_draw(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
