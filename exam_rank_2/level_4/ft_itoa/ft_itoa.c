/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:50:02 by tbrunier          #+#    #+#             */
/*   Updated: 2024/08/04 19:50:02 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_numlen(int nbr)
{
	unsigned int	res;

	res = 0;
	if (nbr <= 0)
	{
		nbr = -nbr;
		res++;
	}
	while (nbr != 0)
	{
		nbr = (nbr / 10);
		res++;
	}
	return (res);
}

char	*ft_itoa(int nbr)
{
	unsigned int	i;
	char			*res;

	i = ft_numlen(nbr);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i--] = 0;
	if (nbr == 0)
		res[i] = 48;
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		res[i] = (48 + (nbr % 10));
		nbr = (nbr / 10);
		i--;
	}
	return (res);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	int		nbr;
	char	*res;

	nbr = atoi(argv[1]);
	printf("before: %d\n", nbr);
	res = ft_itoa(nbr);
	printf("after : %s\n", res);
	free(res);
	return (0);
}*/