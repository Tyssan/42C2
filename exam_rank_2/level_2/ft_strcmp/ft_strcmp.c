/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:04:58 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/16 21:27:14 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*
#include <string.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	(void)ac;
	printf("res1=%d\nres2=%d\n", strcmp(av[1], av[2]), ft_strcmp(av[1], av[2]));
	return (0);
}*/