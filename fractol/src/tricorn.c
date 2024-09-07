/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley_fern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:46:25 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/07 13:46:25 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deep_draw_tricorn(int x, int y, t_data *data)
{
	float	tab[5];
	int		i;

	tab[0] = 1.5f * (((x - WIN_W / 2) + data->img->offset_x)
			/ (0.5f * WIN_W * data->img->zoom));
	tab[1] = (((y - WIN_H / 2) + data->img->offset_y)
			/ (0.5f * WIN_H * data->img->zoom));
	tab[2] = 0.0f;
	tab[3] = 0.0f;
	i = 0;
	while (tab[2] * tab[2] + tab[3] * tab[3] < 4 && i < PRECISION)
	{
		tab[4] = tab[2] * tab[2] - tab[3] * tab[3] + tab[0];
		tab[3] = -2.0f * tab[2] * tab[3] + tab[1];
		tab[2] = tab[4];
		i++;
	}
	return (get_color(i, PRECISION, data->img->color_profile));
}

void	draw_tricorn(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			put_pixel(data, x, y, deep_draw_tricorn(x, y, data));
			x++;
		}
		y++;
	}
	return ;
}
