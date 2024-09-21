/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:49:34 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/20 22:09:37 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*res;
	int	tab_count;
	int	order;
	int	i;

	tab_count = end - start;
	if (tab_count < 0)
		tab_count *= -1;
	tab_count++;
	res = (int *)malloc(sizeof(int) * tab_count);
	if (!res)
		return (NULL);
	order = 1;
	i = 0;
	if (start < end)
		order = -1;
	while (i < tab_count)
	{
		res[i] = end;
		end = end + order;
		i++;
	}
	return (res);
}

/*#include <stdio.h>

int	main(int ac, char **av)
{
	int	*res;
	int	i;

	if (ac == 3)
	{
		res = ft_rrange(atoi(av[1]), atoi(av[2]));
		i = 0;
		while (res[i])
		{
			printf("[%d]=%d\n", i, res[i]);
			i++;
		}
		free(res);
		return (0);
	}
	return (1);
}
*//*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/