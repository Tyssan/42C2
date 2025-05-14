/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:01:58 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/17 19:12:17 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ulstr(char *str)
{
	int	i;
	
	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		write(1, &str[i], 1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_ulstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
