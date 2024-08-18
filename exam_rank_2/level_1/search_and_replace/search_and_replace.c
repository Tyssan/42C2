/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:00:45 by tbrunier          #+#    #+#             */
/*   Updated: 2024/08/18 23:00:45 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_search_and_replace(char *str, char search, char replace)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == search)
			write(1, &replace, 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	return ;
}

int	main(int ac, char **av)
{
	if (ac == 4)
		if (av[1][0] != 0 || av[2][0] != 0 || av[3][0] != 0)
			if (av[2][1] == 0 || av[3][1] == 0)
				ft_search_and_replace(av[1], av[2][0], av[3][0]);
	write(1, "\n", 1);
	return (0);
}
