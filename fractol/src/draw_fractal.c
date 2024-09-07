/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:28:33 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/06 18:28:33 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	get_color(int precision, int max_precision)
{
	int	ratio;
	int	r;
	int	g;
	int	b;

	if (precision >= max_precision)
		return (0x000000);
	ratio = (255 * precision) / max_precision;
	if (ratio < 128)
	{
		r = 255;
		g = 2 * ratio;
		b = 0;
	}
	else
	{
		r = 2 * (255 - ratio);
		g = 2 * (255 - ratio);
		b = 2 * ratio - 255;
	}
	return ((r << 16) | (g << 8) | b);
}

void	draw_fractal(t_data *data)
{
	if (data->img->fractal_type == JULIA)
		draw_julia(data);
	else if (data->img->fractal_type == MANDELBROT)
		draw_mandelbrot(data);
	mlx_put_image_to_window(
		data->mlx_ptr, data->mlx_win_ptr, data->img->img_ptr, 0, 0);
	return ;
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	int	offset;

	offset = (y * data->img->img_line_length) + (x * data->img->img_bpp / 8);
	data->img->img_data_ptr[offset] = color;
	data->img->img_data_ptr[offset + 1] = color >> 8;
	data->img->img_data_ptr[offset + 2] = color >> 16;
	return ;
}
