/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:03:20 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/12 17:18:00 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

long long	ft_atoll(const char *nptr)
{
	int			parity;
	long long	i;
	long long	nb;

	parity = 1;
	i = 0;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			parity = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if ((nb > LLONG_MAX / 10) || \
			(nb == LLONG_MAX / 10 && (nptr[i] - '0') > LLONG_MAX % 10))
		{
			if (parity == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		nb = nb * 10 + (nptr[i++] - '0');
	}
	return (nb * parity);
}
