/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:06:38 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/10 00:08:54 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
/*write*/
# include <stdlib.h>
/*malloc, free, exit*/
# include <math.h>
/*maths functions (fabs, ..)*/
# include <X11/keysym.h>
/*keys input*/
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
	float			c_real;
	float			c_imag;
}	t_image;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*mlx_win_ptr;
	t_image			*img;
}	t_data;

#endif