/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:49:47 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/18 09:57:36 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rotone(char *str)
{
	int	i;
	
	i= -1;
	while (str[++i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (str[i] == 'z' || str[i] == 'Z')
				str[i] = str[i] - 25;
			else
				str[i] = str[i] + 1;
		}
		write(1, &str[i], 1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_rotone(av[1]);
	write(1, "\n", 1);
	return (0);
}
