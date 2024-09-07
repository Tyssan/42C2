/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:04:17 by tbrunier          #+#    #+#             */
/*   Updated: 2024/08/21 16:04:17 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
/*write*/
# include <stdlib.h>
/*malloc, free, exit*/
#include <math.h>
/*maths functions (fabs, ..)*/
# include <X11/keysym.h>
/*keys input*/
#include "../src/libft/include/libft.h"
/*libft*/
#include "../minilibx-linux/mlx.h"
/*mlx*/

# define WIN_W 1069
# define WIN_H 727
# define WIN_NAME "tbrunier's fractol"

# define ZOOM_FACTOR 0.1f
# define PRECISION 21

# define ERROR_BAD_PARAMETER_NUMBER 1
# define ERROR_BAD_FRACTAL_TYPE 2

# define JULIA 1
# define MANDELBROT 2
# define TRICORN 3

typedef struct s_image {
	void			*img_ptr;
	char			*img_data_ptr;
	int				img_bpp;
	int				img_line_length;
	int				img_endian;
	int				fractal_type;
	float			c_real;
	float			c_imag;
	float			zoom;
	float			offset_x;
	float			offset_y;
	int				color_profile;
}				t_image;

typedef struct s_data {
	void			*mlx_ptr;
	void			*mlx_win_ptr;
	t_image			*img;
}				t_data;

// prototype declarations

// draw_fractal.c
int		get_color(int precision, int max_precision, int	cprofile);
void	draw_fractal(t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);

// hooks.c
int		mouse_hook(int button, int x, int y, t_data *data);
int		keys_hook(int key, t_data *data);

// init.c
int		ft_mlx_init(t_data *data);
void	ft_struct_init(t_data *data, int part);
int		ft_init_main(t_data *data);

// julia.c
int		deep_draw_julia(int x, int y, t_data *data);
void	draw_julia(t_data *data);

// main.c
int		terminate_program(t_data *data);
void	check_error(int argc, char **argv);

// mandelbrot.c
int		deep_draw_mandelbrot(int x, int y, t_data *data);
void	draw_mandelbrot(t_data *data);

// tricorn.c
int		deep_draw_tricorn(int x, int y, t_data *data);
void	draw_tricorn(t_data *data);

#endif
