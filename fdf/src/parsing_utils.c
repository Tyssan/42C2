/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:16:07 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/15 16:58:08 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	calculate_zoom(t_fdf *fdf)
{
	float	zoom_x;
	float	zoom_y;

	zoom_x = (WIN_W / (float)fdf->map_x) / 2;
	zoom_y = (WIN_H / (float)fdf->map_y) / 2;
	if (zoom_x < zoom_y)
		return (zoom_x);
	else
		return (zoom_y);
}

bool	ft_file_check(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (write(2, "ERROR: file could'nt be opened: \
check if file exists / if file has read rights\n", 79), 0);
	get_next_line(fd, &line);
	if (line == NULL)
	{
		close(fd);
		return (write(2, "ERROR: empty file", 17), 0);
	}
	close(fd);
	free(line);
	return (1);
}

void	ft_free_matrix_elements(t_fdf *fdf)
{
	long	x;
	long	y;

	y = -1;
	while (++y < fdf->map_y)
	{
		if (fdf->mtx[y])
		{
			x = -1;
			while (++x < fdf->map_x)
			{
				if (fdf->mtx[y][x])
				{
					free(fdf->mtx[y][x]);
					fdf->mtx[y][x] = NULL;
				}
			}
			free(fdf->mtx[y]);
			fdf->mtx[y] = NULL;
		}
	}
}

void	ft_free_matrix(t_fdf *fdf, char *line)
{
	if (fdf && fdf->mtx)
	{
		ft_free_matrix_elements(fdf);
		free(fdf->mtx);
		fdf->mtx = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

void	ft_free_split(char **lines)
{
	unsigned int	i;

	i = 0;
	if (lines)
	{
		while (lines[i])
		{
			free(lines[i]);
			i++;
		}
		free(lines);
	}
}
