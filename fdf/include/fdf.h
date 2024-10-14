/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:06:38 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/14 06:18:42 by tbrunier         ###   ########.fr       */
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

# define WIN_W 1069
# define WIN_H 727
# define WIN_NAME "tbrunier's fdf"

typedef struct s_image
{
	void			*img_ptr;
	char			*img_data_ptr;
	int				img_bpp;
	int				img_line_length;
	int				img_endian;
}	t_image;

typedef struct s_fdf
{
	int				**matrix;
	unsigned int	map_x;
	unsigned int	map_y;
	float			flt_x;
	float			flt_y;
}	t_fdf;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*mlx_win_ptr;
	t_image			*img;
	t_fdf			*fdf;
}	t_data;

/*init.c*/
t_fdf		*ft_fdfstruct_maker(void);
t_image		*ft_imagestruct_maker(void);
void		ft_mlx_destroyer(t_data *data, int code);
bool		ft_mlx_init(t_data *data);
bool		ft_init_main(char *file, t_data *data);

/*main.c*/
int			terminate_program(t_data *data);
int			keys_hook(int key, t_data *data);

/*parsing_utils.c*/
void		ft_free_partial_matrix(int **matrix, unsigned int rows_allocated, char *line);
void		ft_free_matrix(int **matrix, unsigned int map_y);
void		ft_free_split_lines(char **lines);

/*struct_init.c*/
bool		ft_map_size_parsing(int fd, t_fdf *fdf_data);
bool		ft_matrix_init(int fd, t_fdf *fdf_data);
bool		ft_map_parsing(char *file, t_data *data);

#endif
