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
#include <sys/wait.h>/*test*/

void	my_mlx_pixel_put(t_image *data, unsigned int x, unsigned int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
	return ;
}

/*int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}*/

int	ft_draw(int key, t_data *data)
{
	t_image				img;
	static unsigned int	x;
	static unsigned int	y;

	if (key == XK_Escape)
	{
		printf("ESC key (%d) pressed.\n", key);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(img.img);
		free(img.addr);
		exit(1);
	}
	img.img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	if (key == 65361)
	{
		x -= 1;
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, img.img, 0, 0);
	}
	if (key == 65362)
	{
		y -= 1;
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, img.img, 0, 0);
	}
	if (key == 65363)
	{
		x += 1;
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, img.img, 0, 0);
	}
	if (key == 65364)
	{
		y += 1;
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, img.img, 0, 0);
	}
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.mlx_win_ptr = mlx_new_window(data.mlx_ptr, WIN_W, WIN_H, "tbrunier's fract-ol");
	mlx_key_hook(data.mlx_win_ptr, ft_draw, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
