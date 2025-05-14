/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:05:40 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/16 22:15:56 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(unsigned int n)
{
	char	nb;

	if (n >= 10)
		ft_putnbr(n / 10);
	nb = (n % 10) + '0';
	write(1, &nb, 1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}

/*
Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>
*/