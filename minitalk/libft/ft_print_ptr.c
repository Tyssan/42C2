/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 07:35:05 by tbrunier          #+#    #+#             */
/*   Updated: 2024/05/20 07:35:05 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

unsigned int	ft_count_ptr(uintptr_t hexvalue)
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

void	ft_write_ptr(uintptr_t hexvalue)
{
	if (hexvalue >= 16)
	{
		ft_write_ptr(hexvalue / 16);
		ft_write_ptr(hexvalue % 16);
	}
	else
	{
		if (hexvalue <= 9)
			ft_putchar_fd((hexvalue + '0'), 1);
		else
			ft_putchar_fd((hexvalue - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	if (ptr == 0)
		count += write(1, "0", 1);
	else
	{
		ft_write_ptr(ptr);
		count += ft_count_ptr(ptr);
	}
	return (count);
}
