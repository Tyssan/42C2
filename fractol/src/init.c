/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:13:00 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/04 15:13:00 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_mlx_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	data->mlx_win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, WIN_NAME);
	if (!data->mlx_win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (0);
	}
	data->img = malloc(sizeof(t_image));
	if (!data->img)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data->img);
		return (0);
	}
	ft_struct_init(data, 2);
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	data->img->img_data_ptr = mlx_get_data_addr(
			data->img->img_ptr, &data->img->img_bpp, \
			&data->img->img_line_length, &data->img->img_endian);
	return (1);
}

void	ft_struct_init(t_data *data, int part)
{
	if (part == 1)
	{
		data->mlx_ptr = NULL;
		data->mlx_win_ptr = NULL;
		data->img = NULL;
	}
	else if (part == 2)
	{
		data->img->img_ptr = NULL;
		data->img->img_data_ptr = NULL;
		data->img->img_bpp = 0;
		data->img->img_line_length = 0;
		data->img->img_endian = 0;
		data->img->fractal_type = 0;
		data->img->c_real = 0.0f;
		data->img->c_imag = 0.0f;
		data->img->zoom = 1.0f;
		data->img->offset_x = 0.0f;
		data->img->offset_y = 0.0f;
		data->img->color_profile = 1;
	}
	return ;
}

int	ft_init_main(t_data *data)
{
	ft_struct_init(data, 1);
	if (!ft_mlx_init(data))
		return (0);
	return (1);
}
