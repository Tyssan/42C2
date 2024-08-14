/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:04:32 by tbrunier          #+#    #+#             */
/*   Updated: 2024/08/02 19:59:37 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_already_occured(char *str1, char letter, unsigned int n)
{
	int	i;

	i = (n - 1);
	while (i >= 0)
	{
		if (str1[i] == letter)
			return (1);
		i--;
	}
	return (0);
}

void	ft_inter(char *str1, char *str2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (str1[i])
	{
		while (str2[j])
		{
			if (str1[i] == str2[j])
			{
				if (ft_already_occured(str1, str1[i], i) == 0)
					write(1, &str1[i], 1);
				break ;
			}
			else
				j++;
		}
		j = 0;
		i++;
	}
	return ;
}

int	main(int ac, char **av)
{
	if (ac == 3)
		ft_inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
