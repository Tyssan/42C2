/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:16:07 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/14 04:56:14 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void ft_free_partial_matrix(int **matrix, unsigned int rows_allocated, char *line)
{
	unsigned int	i;
	
	i = 0;
	if (matrix)
	{
		while (i < rows_allocated)
		{
			if (matrix[i])
				free(matrix[i]);
			i++;
		}
		free(matrix);
	}
	free(line);
}

void	ft_free_matrix(int **matrix, unsigned int map_y)
{
	unsigned int	i;

	i = 0;
	if (matrix)
	{
		while (i < map_y)
		{
			if (matrix[i])
				free(matrix[i]);
			i++;
		}
		free(matrix);
	}
}

void	ft_free_split_lines(char **lines)
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
