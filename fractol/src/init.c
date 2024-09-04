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
#include "./libft/include/libft.h"
#include "../minilibx-linux/mlx.h"

int	ft_pixel_init(t_data *data)
{
	data->pixels = new_pixel(WIN_W / 2, WIN_H / 2, 0x00FF0000);
	if (!data->pixels)
	{
		free(data->keys_state);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (0);
	}
	return (1);
}

int	ft_keys_state_init(t_data *data)
{
	data->keys_state = malloc(sizeof(t_keystate));
	if (!data->keys_state)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (0);
	}
	data->keys_state->left = 0;
	data->keys_state->right = 0;
	data->keys_state->up = 0;
	data->keys_state->down = 0;
	return (1);
}

int	ft_mlx_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	data->mlx_win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "tbrunier's fract-ol");
	if (!data->mlx_win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (0);
	}
	return (1);
}

void	ft_null_init(t_data *data)
{
	data->mlx_ptr = NULL;
	data->mlx_win_ptr = NULL;
	data->keys_state = NULL;
	data->pixels = NULL;
	data->rainbow_mode = 1;
	return ;
}

int	ft_data_init(t_data *data)
{
	ft_null_init(data);
	if (!ft_mlx_init(data))
		return (0);
	if (!ft_keys_state_init(data))
		return (0);
	if (!ft_pixel_init(data))
		return (0);
	return (1);
}
