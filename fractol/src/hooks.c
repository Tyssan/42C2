/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:22:40 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/06 18:22:40 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractal_reset(t_data *data)
{
	data->img->zoom = 1.0f;
	data->img->offset_x = 0.0f;
	data->img->offset_y = 0.0f;
	draw_fractal(data);
	return ;
}

int	keys_hook(int key, t_data *data)
{
	float	move_speed;

	move_speed = 69.0f * data->img->zoom;
	if (key == XK_Escape)
		terminate_program(data);
	else if (key == XK_r)
		fractal_reset(data);
	else if (key == XK_Left)
		data->img->offset_x -= move_speed / data->img->zoom;
	else if (key == XK_Right)
		data->img->offset_x += move_speed / data->img->zoom;
	else if (key == XK_Up)
		data->img->offset_y -= move_speed / data->img->zoom;
	else if (key == XK_Down)
		data->img->offset_y += move_speed / data->img->zoom;
	draw_fractal(data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	float	zoom_factor;

	(void)x;
	(void)y;
	if (button == 4)
		zoom_factor = 1.1f;
	else if (button == 5)
		zoom_factor = 1.0f / 1.1f;
	else
		return (0);
	data->img->zoom *= zoom_factor;
	draw_fractal(data);
	return (0);
}
