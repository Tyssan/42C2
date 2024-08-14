/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:55:36 by tbrunier          #+#    #+#             */
/*   Updated: 2024/08/04 18:55:36 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_repeat_alpha(char *str)
{
	int	i;
	int	repeat;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 66 && str[i] <= 90)
		{
			repeat = (str[i] - 64);
			while (repeat-- > 0)
				write(1, &str[i], 1);
		}
		else if (str[i] >= 98 && str[i] <= 122)
		{
			repeat = (str[i] - 96);
			while (repeat-- > 0)
				write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_repeat_alpha(argv[1]);
	write(1, "\n", 1);
	return (0);
}
