/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:28:13 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/15 20:00:24 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	absol(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	interpolate_color(int color1, int color2, float factor)
{
	int	red;
	int	green;
	int	blue;

	red = ((color1 >> 16) & 0xFF) + factor * (((color2 >> 16)
				& 0xFF) - ((color1 >> 16) & 0xFF));
	green = ((color1 >> 8) & 0xFF) + factor * (((color2 >> 8)
				& 0xFF) - ((color1 >> 8) & 0xFF));
	blue = (color1 & 0xFF) + factor * ((color2 & 0xFF)
			- (color1 & 0xFF));
	return ((red << 16) | (green << 8) | blue);
}

int	get_color(int value)
{
	int		color1;
	int		color2;
	float	factor;

	if (value >= 50)
	{
		color1 = 0xFFFF00;
		color2 = 0xFF0000;
		factor = (value - 50) / 50.0;
	}
	else if (value >= 25)
	{
		color1 = 0x00FF00;
		color2 = 0xFFFF00;
		factor = (value - 25) / 25.0;
	}
	else
	{
		color1 = 0x0000FF;
		color2 = 0x00FF00;
		factor = value / 25.0;
	}
	return (interpolate_color(color1, color2, factor));
}

void	ft_algo_init(t_bresenham *value, t_algo_init *init_value, int y1)
{
	value->dx = absol(init_value->x1 - init_value->x0);
	value->dy = absol(y1 - init_value->y0);
	if (init_value->x0 < init_value->x1)
		value->sx = 1;
	else
		value->sx = -1;
	if (init_value->y0 < y1)
		value->sy = 1;
	else
		value->sy = -1;
	value->err = value->dx - value->dy;
}

void	config_cord(t_fdf *fdf, int x, int y, int offset)
{
	if (offset == 0)
	{
		fdf->x = x;
		fdf->y = y;
		fdf->x1 = x + 1;
		fdf->y1 = y;
	}
	else
	{
		fdf->x = x;
		fdf->y = y;
		fdf->x1 = x;
		fdf->y1 = y + 1;
	}
}
