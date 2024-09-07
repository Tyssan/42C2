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

int	keys_hook(int key, t_data *data)
{
	if (key == XK_Escape)
		terminate_program(data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	float	zoom_factor;

	(void)x;
	(void)y;
	zoom_factor = 1.0f;
	if (button == 4)
		zoom_factor += ZOOM_FACTOR;
	else if (button == 5)
		zoom_factor -= ZOOM_FACTOR;
	data->img->zoom *= zoom_factor;
	draw_fractal(data);
	return (0);
}
