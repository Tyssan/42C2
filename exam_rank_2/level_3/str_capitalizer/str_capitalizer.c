/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:34:32 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/04 17:35:00 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_str_capitalizer(char *str)
{
	int		i = -1;
	char	ul_case;
	if (!str)
		return ;
	while (str[++i])
	{
		if ((str[i] >= 97 && str[i] <= 122) && ((str[i - 1] == 0) || (str[i - 1] == 32) || (str[i - 1] >= 9 && str[i - 1] <= 13)))
			ul_case = (str[i] - 32);
		else if ((str[i] >= 65 && str[i] <= 90) && !((str[i - 1] == 0) || (str[i - 1] == 32) || (str[i - 1] >= 9 && str[i - 1] <= 13)))
			ul_case = (str[i] + 32);
		else
			ul_case = str[i];
		write(1, &ul_case, 1);
	}
}

int	main(int argc, char **argv)
{
	int	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			ft_str_capitalizer(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
