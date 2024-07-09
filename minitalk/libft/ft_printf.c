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
	if (format == 'u')
		count += unsigned_de_merde(va_arg(args, long));
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
