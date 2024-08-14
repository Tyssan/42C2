/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:14:34 by tbrunier          #+#    #+#             */
/*   Updated: 2024/08/04 19:14:34 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rstr_capitalizer(char *str)
{
	int		i;
	char	capitalized;

	i = 0;
	while(str[i])
	{
		if ((str[i] >= 97 && str[i] <= 122) && \
		((str[i + 1] >= 9 && str[i + 1] <= 13) || \
		str[i + 1] == 32 || str[i + 1] == 0))
		{
			capitalized = (str[i] - 32);
			write(1, &capitalized, 1);
		}
		else if ((str[i] >= 65 && str[i] <= 90) && \
		((str[i + 1] >= 9 && str[i + 1] <= 13) || \
		str[i + 1] == 32 || str[i + 1] == 0))
			write(1, &str[i], 1);
		else if ((str[i] >= 65 && str[i] <= 90) && \
		(!(str[i + 1] >= 9 && str[i + 1] <= 13) || \
		str[i + 1] == 32 || str[i + 1] == 0))
		{
			capitalized = (str[i] + 32);
			write(1, &capitalized, 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return ;
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 1)
		while (++i < argc)
			ft_rstr_capitalizer(argv[i]);
	else
		write(1, "\n", 1);
	return (0);
}
