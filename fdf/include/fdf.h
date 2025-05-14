/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:06:38 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/15 19:32:24 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
/*write*/
# include <stdlib.h>
/*malloc, free, exit*/
# include <fcntl.h>
/*O_RDONLY keyword definition*/
# include <math.h>
/*maths functions (fabs, ..)*/
# include <X11/keysym.h>
/*keys input*/
# include <stdbool.h>
/*variable bool*/
# include "../src/libft/include/libft.h"
/*libft*/
# include "../minilibx-linux/mlx.h"
/*mlx*/

# define WIN_W 1727
# define WIN_H 1069
# define WIN_NAME "tbrunier's fdf"

typedef struct s_algo_init
{
	int				x0;
	int				y0;
	int				x1;
}	t_algo_init;

typedef struct s_bresenham
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}	t_bresenham;

typedef struct s_mat_init
{
	long	i_pos;
	long	j_value;
	char	**split;
	char	*line;
}	t_mat_init;

typedef struct s_fdf
{
	int				***mtx;
	unsigned int	map_x;
	unsigned int	map_y;
	int				min;
	int				min2;
	int				xmove;
	int				ymove;
	float			x;
	float			y;
	float			x1;
	float			y1;
	float			rx;
	float			ry;
	float			rz;
	float			zoom;
	int				color;
}	t_fdf;

typedef struct s_image
{
	void			*img_ptr;
	char			*img_data_ptr;
	int				img_bpp;
	int				img_line_length;
	int				img_endian;
}	t_image;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*mlx_win_ptr;
	int				color;
	t_image			*img;
	t_fdf			*fdf;
}	t_data;

/*draw_init.c*/
int			absol(int n);
int			get_color(int value);
void		ft_algo_init(t_bresenham *value, t_algo_init *init_value, int y1);
void		config_cord(t_fdf *fdf, int x, int y, int offset);

/*draw.c*/
void		iso(t_data *data, int z1, int z2);
void		put_pixel(t_data *data, int x, int y, int color);
void		bresenham(t_data *data, int x0, int y0, int x1);
void		draw_lines(t_data *data);
int			ft_draw(t_data *data);

/*init.c*/
t_fdf		*ft_fdfstruct_maker(void);
t_image		*ft_imagestruct_maker(void);
void		ft_mlx_destroyer(t_data *data, int code);
bool		ft_mlx_init(t_data *data);
bool		ft_init_main(char *file, t_data *data);

/*main.c*/
int			terminate_program(t_data *data);
int			keys_hook(int key, t_data *data);
/*int		main(int argc, char **argv);*/

/*parsing_utils.c*/
float		calculate_zoom(t_fdf *fdf);
bool		ft_file_check(char *file);
void		ft_free_matrix_elements(t_fdf *fdf);
void		ft_free_matrix(t_fdf *fdf, char *line);
void		ft_free_split(char **lines);

/*struct_init.c*/
bool		ft_map_size_parsing(int fd, t_fdf *fdf);
int			***ft_matrix_maker(unsigned int size);
bool		ft_matrix_init(int fd, t_fdf *fdf);
void		ft_get_min(t_data *data);
bool		ft_map_parsing(char *file, t_data *data);

#endif
