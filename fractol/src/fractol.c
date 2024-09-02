/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:14:59 by tbrunier          #+#    #+#             */
/*   Updated: 2024/08/21 18:14:59 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "./libft/include/libft.h"
#include "../minilibx-linux/mlx.h"

t_pixel	*new_pixel(unsigned int x, unsigned int y, int color)
{
	t_pixel	*new;

	new = (t_pixel *)malloc(sizeof(t_pixel));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->color = color;
	new->next = NULL;
	return (new);
}

void	add_pixel(t_pixel **pixels, unsigned int x, unsigned int y, int color)
{
	t_pixel	*new;
	t_pixel	*current;

	new = new_pixel(x, y, color);
	if (!new)
		return ;
	if (!*pixels)
		*pixels = new;
	else
	{
		current = *pixels;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

void	my_mlx_pixel_put(t_image *img, unsigned int x, unsigned int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
	return ;
}

void	ft_draw(t_data *data)
{
	t_image	img;
	t_pixel	*current;

	img.img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	current = data->pixels;
	while (current)
	{
		my_mlx_pixel_put(&img, current->x, current->y, current->color);
		current = current->next;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, img.img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, img.img);
}

int	update_position(t_data *data, t_keys *keys)
{
	if (keys->left && data->pixels->x > 0)
		data->pixels->x -= 1;
	if (keys->right && data->pixels->x < WIN_W - 1)
		data->pixels->x += 1;
	if (keys->up && data->pixels->y > 0)
		data->pixels->y -= 1;
	if (keys->down && data->pixels->y < WIN_H - 1)
		data->pixels->y += 1;
	add_pixel(&data->pixels, data->pixels->x, data->pixels->y, data->pixels->color);
	ft_draw(data);
	return (0);
}

int	key_press(int key, t_keys *keys)
{
	if (key == XK_Left)
		keys->left = 1;
	if (key == XK_Right)
		keys->right = 1;
	if (key == XK_Up)
		keys->up = 1;
	if (key == XK_Down)
		keys->down = 1;
	return (0);
}

int	key_release(int key, t_keys *keys)
{
	if (key == XK_Left)
		keys->left = 0;
	if (key == XK_Right)
		keys->right = 0;
	if (key == XK_Up)
		keys->up = 0;
	if (key == XK_Down)
		keys->down = 0;
	return (0);
}

void	free_pixels(t_pixel *pixels)
{
	t_pixel	*tmp;

	while (pixels)
	{
		tmp = pixels;
		pixels = pixels->next;
		free(tmp);
	}
}

void	erase_program(t_data *data)
{
	free_pixels(data->pixels);
	data->pixels = NULL;
}

void	keys_handler(t_data *data, int key)
{
	if (key == XK_r)
	{
		data->pixels->x = WIN_W / 2;
		data->pixels->y = WIN_H / 2;
	}
	if (key == XK_e)
		erase_program(data);
}

void	ft_stop_and_clean(t_data *data, int key)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free_pixels(data->pixels);
		free(data->mlx_ptr);
		exit(0);
	}
	return ;
}

int	loop_hook(int key, t_data *data)
{
	update_position(data, data->keys_state);
	ft_stop_and_clean(data , key);
	keys_handler(data , key);
	return (0);
}

void init_keys(t_keys *keys)
{
	keys->left = 0;
	keys->right = 0;
	keys->up = 0;
	keys->down = 0;
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.mlx_win_ptr = mlx_new_window(data.mlx_ptr, WIN_W, WIN_H, "tbrunier's fract-ol");
	init_keys(&data.keys_state);
	data.pixels = new_pixel(WIN_W / 2, WIN_H / 2, 0x00FF0000);
	mlx_hook(data.mlx_win_ptr, KeyPress, KeyPressMask, key_press, &data.keys_state);
	mlx_hook(data.mlx_win_ptr, KeyRelease, KeyReleaseMask, key_release, &data.keys_state);
	mlx_key_hook(data.mlx_win_ptr, loop_hook, &data);
	mlx_loop(data.mlx_ptr);
	free_pixels(data.pixels);
	return (0);
}
