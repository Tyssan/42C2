/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:54:17 by tbrunier          #+#    #+#             */
/*   Updated: 2024/05/14 21:54:17 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

int	ft_print_str(char *str)
{
	int	count;
	int	i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		count++;
	}
	return (count);
}

int	ft_print_nbr(int nbr)
{
	int		count;
	char	*nbrstr;

	count = 0;
	nbrstr = ft_itoa(nbr);
	count = ft_print_str(nbrstr);
	free (nbrstr);
	return (count);
}
