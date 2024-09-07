/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:14:59 by tbrunier          #+#    #+#             */
/*   Updated: 2024/08/21 18:14:59 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	terminate_program(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	mlx_loop_end(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->img);
	exit(0);
	return (0);
}

void	check_error(int argc, char **argv)
{
	if (argc == 2 && (!ft_strcmp(argv[1], "mandelbrot")
			|| !ft_strcmp(argv[1], "tricorn")))
		return ;
	if (argc == 4 && !ft_strcmp(argv[1], "julia"))
		return ;
	write(2, "ERROR : BAD PARAMETER NUMBER\n", 29);
	write(2, "LIST OF USAGES :\n", 17);
	write(2, "\t./fractol julia [INT|C_REAL] [INT|C_IMAG]\n", 43);
	write(2, "\t./fractol mandelbrot\n", 22);
	write(2, "\t./fractol tricorn\n", 19);
	exit(ERROR_BAD_PARAMETER_NUMBER);
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_error(argc, argv);
	if (!ft_init_main(&data))
		return (1);
	if (!ft_strcmp(argv[1], "julia"))
	{
		data.img->fractal_type = JULIA;
		data.img->c_real = -0.7f + ((float)(ft_atoi(argv[2])) / 100.0f);
		data.img->c_imag = 0.27015f + ((float)(ft_atoi(argv[3])) / 100.0f);
	}
	else if (!ft_strcmp(argv[1], "mandelbrot"))
		data.img->fractal_type = MANDELBROT;
	else if (!ft_strcmp(argv[1], "tricorn"))
		data.img->fractal_type = TRICORN;
	draw_fractal(&data);
	mlx_key_hook(data.mlx_win_ptr, keys_hook, &data);
	mlx_mouse_hook(data.mlx_win_ptr, mouse_hook, &data);
	mlx_hook(data.mlx_win_ptr, 17, 0, terminate_program, &data);
	mlx_loop(data.mlx_ptr);
	terminate_program(&data);
	return (0);
}
