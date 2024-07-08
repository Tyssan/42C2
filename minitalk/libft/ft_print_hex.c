/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 04:19:33 by tbrunier          #+#    #+#             */
/*   Updated: 2024/05/20 04:19:33 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

unsigned int	ft_count_hex(unsigned int hexvalue)
{
	int	i;

	i = 0;
	while (hexvalue != 0)
	{
		hexvalue = hexvalue / 16;
		i++;
	}
	return (i);
}

void	ft_write_hex(unsigned int hexvalue, const char format)
{
	if (hexvalue >= 16)
	{
		ft_write_hex(hexvalue / 16, format);
		ft_write_hex(hexvalue % 16, format);
	}
	else
	{
		if (hexvalue <= 9)
			ft_putchar_fd((hexvalue + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((hexvalue - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((hexvalue - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int hexvalue, const char format)
{
	int	count;

	if (hexvalue == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_write_hex(hexvalue, format);
	count = ft_count_hex(hexvalue);
	return (count);
}
