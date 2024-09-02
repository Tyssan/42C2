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

int	update_position(t_data *data)
{
	if (data->keys_state->left && !data->keys_state->right)
	{
		if (data->pixels->x > 0)
			data->pixels->x -= 1;
	}
	if (data->keys_state->right && !data->keys_state->left)
	{
		if (data->pixels->x < WIN_W - 1)
			data->pixels->x += 1;
	}
	if (data->keys_state->up && !data->keys_state->down)
	{
		if (data->pixels->y > 0)
			data->pixels->y -= 1;
	}
	if (data->keys_state->down && !data->keys_state->up)
	{
	if (data->pixels->y < WIN_H - 1)
			data->pixels->y += 1;
	}
	add_pixel(&data->pixels, data->pixels->x, data->pixels->y, data->pixels->color);
	ft_draw(data);
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
	data->pixels = new_pixel(WIN_W / 2, WIN_H / 2, 0x00FF0000);
}

void	keys_handler(int key, t_data *data)
{
	if (key == XK_r)
	{
		data->pixels->x = WIN_W / 2;
		data->pixels->y = WIN_H / 2;
	}
	if (key == XK_e)
		erase_program(data);
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free_pixels(data->pixels);
		free(data->mlx_ptr);
		free(data->keys_state);
		exit(0);
	}
}

int	key_press(int key, t_data *data)
{
	if (!data || !data->keys_state)
		return (0);
	if (key == XK_Left)
		data->keys_state->left = 1;
	if (key == XK_Right)
		data->keys_state->right = 1;
	if (key == XK_Up)
		data->keys_state->up = 1;
	if (key == XK_Down)
		data->keys_state->down = 1;
	keys_handler(key, data);
	printf("Pre - Left: %d, Right: %d, Up: %d, Down: %d\n", data->keys_state->left, data->keys_state->right, data->keys_state->up, data->keys_state->down);
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (!data || !data->keys_state)
		return (0);
	if (key == XK_Left)
		data->keys_state->left = 0;
	if (key == XK_Right)
		data->keys_state->right = 0;
	if (key == XK_Up)
		data->keys_state->up = 0;
	if (key == XK_Down)
		data->keys_state->down = 0;
	printf("Rel - Left: %d, Right: %d, Up: %d, Down: %d\n", data->keys_state->left, data->keys_state->right, data->keys_state->up, data->keys_state->down);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.mlx_win_ptr = mlx_new_window(data.mlx_ptr, WIN_W, WIN_H, "tbrunier's fract-ol");
	data.keys_state = malloc(sizeof(t_keystate));
	if (!data.keys_state)
		return (1);
	data.keys_state->left = 0;
	data.keys_state->right = 0;
	data.keys_state->up = 0;
	data.keys_state->down = 0;
	data.pixels = new_pixel(WIN_W / 2, WIN_H / 2, 0x00FF0000);
	mlx_hook(data.mlx_win_ptr, KeyPress, KeyPressMask, key_press, &data);
	mlx_hook(data.mlx_win_ptr, KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_loop_hook(data.mlx_ptr, update_position, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
