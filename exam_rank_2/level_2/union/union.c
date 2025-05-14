/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:13:28 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/17 19:50:04 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_union(char *str1, char *str2)
{
	unsigned char	seen[256] = {0};
	int				i;

	i = -1;
	while (str1[++i])
	{
		if (seen[(unsigned char)str1[i]] == 0)
		{
			write(1, &str1[i], 1);
			seen[(unsigned char)str1[i]] = 1;
		}
	}
	i = -1;
	while (str2[++i])
	{
		if (seen[(unsigned char)str2[i]] == 0)
		{
			write(1, &str2[i], 1);
			seen[(unsigned char)str2[i]] = 1;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
