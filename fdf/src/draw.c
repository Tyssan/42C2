/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:24:13 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/15 19:53:48 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	iso(t_data *data, int z1, int z2)
{
	float	temp_x;
	float	temp_y;
	float	temp_x1;
	float	temp_y1;
	float	angle;

	angle = 0.45;
	temp_x = data->fdf->x * data->fdf->zoom;
	temp_y = data->fdf->y * data->fdf->zoom;
	temp_x1 = data->fdf->x1 * data->fdf->zoom;
	temp_y1 = data->fdf->y1 * data->fdf->zoom;
	data->fdf->x = (temp_x - temp_y) * cos(angle) + (WIN_W / 1.5)
		- ((data->fdf->map_x * data->fdf->zoom) / 2);
	data->fdf->y = (temp_x + temp_y) * sin(angle) - z1 + (WIN_H / 1.75)
		- ((data->fdf->map_y * data->fdf->zoom) / 2);
	data->fdf->x1 = (temp_x1 - temp_y1) * cos(angle) + (WIN_W / 1.5)
		- ((data->fdf->map_x * data->fdf->zoom) / 2);
	data->fdf->y1 = (temp_x1 + temp_y1) * sin(angle) - z2 + (WIN_H / 1.75)
		- ((data->fdf->map_y * data->fdf->zoom) / 2);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		dst = data->img->img_data_ptr + (y * data->img->img_line_length
				+ x * (data->img->img_bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	bresenham(t_data *data, int x0, int y0, int x1)
{
	t_bresenham	value;
	t_algo_init	init_value;

	init_value.x0 = x0;
	init_value.x1 = x1;
	init_value.y0 = y0;
	ft_algo_init(&value, &init_value, (int)data->fdf->y1);
	while (1)
	{
		put_pixel(data, x0, y0, data->color);
		if (x0 == x1 && y0 == (int)data->fdf->y1)
			break ;
		value.e2 = 2 * value.err;
		if (value.e2 > -value.dy)
		{
			value.err -= value.dy;
			x0 += value.sx;
		}
		if (value.e2 < value.dx)
		{
			value.err += value.dx;
			y0 += value.sy;
		}
	}
}

void	draw_lines(t_data *data)
{
	long	i;
	long	j;

	i = -1;
	j = -1;
	while (++i < data->fdf->map_y)
	{
		while (++j < data->fdf->map_x)
		{
			data->color = get_color(data->fdf->mtx[i][j][0]);
			if (j < data->fdf->map_x - 1)
			{
				config_cord(data->fdf, j, i, 0);
				iso(data, data->fdf->mtx[i][j][0], data->fdf->mtx[i][j + 1][0]);
				bresenham(data, data->fdf->x, data->fdf->y, data->fdf->x1);
			}
			if (i < data->fdf->map_y - 1)
			{
				config_cord(data->fdf, j, i, 1);
				iso(data, data->fdf->mtx[i][j][0], data->fdf->mtx[i + 1][j][0]);
				bresenham(data, data->fdf->x, data->fdf->y, data->fdf->x1);
			}
		}
		j = -1;
	}
}

int	ft_draw(t_data *data)
{
	draw_lines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr,
		data->img->img_ptr, 0, 0);
	return (0);
}
