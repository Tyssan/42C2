/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 06:57:43 by tbrunier          #+#    #+#             */
/*   Updated: 2024/05/20 06:57:43 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

int	ft_unumlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_unumlen(n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	while (n != 0)
	{
		str[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int n)
{
	int		count;
	char	*str;

	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		str = ft_uitoa(n);
		count = ft_print_str(str);
		free (str);
	}
	return (count);
}
