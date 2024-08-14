/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:30:02 by tbrunier          #+#    #+#             */
/*   Updated: 2024/08/03 17:30:02 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_do_op(int a, char sign, int b)
{
	int	res;

	if (sign == '+')
		res = a + b;
	else if (sign == '-')
		res = a - b;
	else if (sign == '*')
		res = a * b;
	else if (sign == '%')
		res = a % b;
	else if (sign == '/')
		res = a / b;
	printf("%d\n", res);
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		ft_do_op(atoi(argv[1]), argv[2][0], atoi(argv[3]));
	else
		write(1, "\n", 1);
	return (0);
}
