/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:57:16 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/20 13:38:14 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_print(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	while (--i >= 0)
		write(1, &str[i], 1);
	return ;
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_rev_print(av[1]);
	write(1, "\n", 1);
	return (0);
}
