/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:43:17 by tbrunier          #+#    #+#             */
/*   Updated: 2024/05/14 21:43:17 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	unsigned_de_merde(long num)
{
	long	count;

	count = 0;
	if (num < 0)
		num = 4294967296 - (-num);
	count = ft_print_unsigned((unsigned int)num);
	return (count);
}

int	ft_formats(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (format == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		count += ft_print_nbr(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == 'u')
		count += unsigned_de_merde(va_arg(args, long));
	else if (format == '%')
	{
		write(1, "%", 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			count += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
