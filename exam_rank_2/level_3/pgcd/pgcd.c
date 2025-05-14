/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:48:12 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/09 16:50:46 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_pgcd_calc(int Snb, int Bnb)
{
	unsigned long	tmp;

	while (Bnb != 0)
	{
		tmp = Bnb;
		Bnb = Snb % Bnb;
		Snb = tmp;
	}
	printf("%d", Snb);
}

void	ft_pgcd(int	nb1, int nb2)
{
	if (nb1 == nb2)
		printf("%d", nb1);
	else if (nb1 < nb2)
		ft_pgcd_calc(nb1, nb2);
	else if (nb1 > nb2)
		ft_pgcd_calc(nb2, nb1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_pgcd(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return (0);
}
