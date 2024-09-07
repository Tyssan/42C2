/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcavaill < tcavaill@student.42perpignan    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 06:35:22 by tcavaill          #+#    #+#             */
/*   Updated: 2024/08/02 06:35:22 by tcavaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deep_draw_julia(int x, int y, t_data *data)
{
	float	zx;
	float	zy;
	float	tmp;
	int		i;

	zx = 1.5f * (x - WIN_W / 2) / (0.5f * WIN_W * data->img->zoom);
	zy = (y - WIN_H / 2) / (0.5f * WIN_H * data->img->zoom);
	i = 0;
	while (zx * zx + zy * zy < 4 && i < PRECISION)
	{
		tmp = zx * zx - zy * zy + data->img->c_real;
		zy = 2.0f * zx * zy + data->img->c_imag;
		zx = tmp;
		i++;
	}
	return (get_color(i, PRECISION));
}

void	draw_julia(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			put_pixel(data, x, y, deep_draw_julia(x, y, data));
			x++;
		}
		y++;
	}
}
