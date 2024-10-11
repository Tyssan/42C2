/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:16:07 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/12 01:11:17 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"



void	ft_free_split_lines(char **lines)
{
	unsigned int	i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
}
