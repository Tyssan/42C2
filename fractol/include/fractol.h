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
/*write, read, close, access, pipe, dup, dup2, execve, fork*/
# include <stdlib.h>
/*malloc, free, exit*/
# include <fcntl.h>
/*open, unlink, exit, EXIT_FAILURE macro, EXIT_SUCCES macro*/
# include <string.h>
/*strerror*/
# include <stdio.h>
/*perror*/
# include <errno.h>
/*errno global variable for perror*/
# include <math.h>
/*maths functions*/
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/Xlib.h>
/*keys input*/

# define WIN_W 800
# define WIN_H 600

typedef struct s_keystate
{
	int				left;
	int				right;
	int				up;
	int				down;
}				t_keystate;

typedef struct s_pixel
{
	unsigned int	x;
	unsigned int	y;
	int				color;
	struct s_pixel	*next;
}				t_pixel;

typedef struct	s_data {
	void			*mlx_ptr;
	void			*mlx_win_ptr;
	t_pixel			*pixels;
	t_keystate		*keys_state;
}				t_data;

typedef struct	s_image {
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}				t_image;

#endif
