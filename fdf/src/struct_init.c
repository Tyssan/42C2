/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 00:38:48 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/15 18:00:40 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

bool	ft_map_size_parsing(int fd, t_fdf *fdf)
{
	unsigned int	line_size;
	char			**split_lines;
	char			*line;

	while (get_next_line(fd, &line) == 1)
	{
		line_size = 0;
		split_lines = ft_split(line, ' ');
		if (!split_lines)
			return (0);
		while (split_lines[line_size])
			line_size++;
		if (fdf->map_x == 0)
			fdf->map_x = line_size;
		ft_free_split(split_lines);
		free(line);
		if (fdf->map_x != line_size)
			return (0);
		fdf->map_y++;
	}
	return (1);
}

int	***ft_matrix_maker(unsigned int size)
{
	int				***mtx;
	unsigned int	i;

	mtx = malloc(sizeof(int **) * size);
	if (!mtx)
		return (NULL);
	i = 0;
	while (i < size)
	{
		mtx[i] = NULL;
		i++;
	}
	return (mtx);
}

bool	ft_matrix_init(int fd, t_fdf *fdf)
{
	t_mat_init	m;

	fdf->mtx = ft_matrix_maker(fdf->map_y);
	if (!fdf->mtx)
		return (0);
	m.i_pos = -1;
	while (get_next_line(fd, &m.line) == 1)
	{
		fdf->mtx[++m.i_pos] = malloc(sizeof(int *) * fdf->map_x);
		if (!fdf->mtx[m.i_pos])
			return (ft_free_matrix(fdf, m.line), 0);
		m.split = ft_split(m.line, ' ');
		if (!m.split)
			return (ft_free_matrix(fdf, m.line), 0);
		m.j_value = -1;
		while (++m.j_value < fdf->map_x)
		{
			fdf->mtx[m.i_pos][m.j_value] = malloc(sizeof(int));
			if (!fdf->mtx[m.i_pos][m.j_value])
				return (ft_free_matrix(fdf, m.line), ft_free_split(m.split), 0);
			*(fdf->mtx[m.i_pos][m.j_value]) = ft_atoi(m.split[m.j_value]);
		}
		(void)(ft_free_split(m.split), free(m.line));
	}
	return (1);
}

void	ft_get_min(t_data *data)
{
	long	i;
	long	j;

	i = -1;
	j = -1;
	data->fdf->min = 2147483647;
	data->fdf->min2 = -2147483648;
	while (++i < data->fdf->map_y)
	{
		j = -1;
		while (++j < data->fdf->map_x)
		{
			if (data->fdf->min > data->fdf->mtx[i][j][0]
				&& data->fdf->mtx[i][j][0] > 0)
				data->fdf->min = data->fdf->mtx[i][j][0];
			if (data->fdf->min2 < data->fdf->mtx[i][j][0]
				&& data->fdf->mtx[i][j][0] < 0)
				data->fdf->min2 = data->fdf->mtx[i][j][0];
		}
	}
}

bool	ft_map_parsing(char *file, t_data *data)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (write(2, "ERROR: file could'nt be opened", 31), 0);
	if (!ft_map_size_parsing(fd, data->fdf))
	{
		free(data->img);
		close(fd);
		return (write(2, "ERROR: incorrect map size\n", 26), 0);
	}
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (write(2, "ERROR: file could'nt be opened", 31), 0);
	if (!ft_matrix_init(fd, data->fdf))
	{
		free(data->img);
		ft_free_matrix(data->fdf, NULL);
		close(fd);
		return (write(2, "ERROR: matrix init failed\n", 26), 0);
	}
	ft_get_min(data);
	return (close(fd), 1);
}
