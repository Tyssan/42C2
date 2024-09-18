/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:49:10 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/12 17:50:08 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(const char *message)
{
	write(2, message, ft_strlen(message));
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		exit(1);
	stack_a = ft_allocate_stack();
	stack_b = ft_allocate_stack();
	if (!stack_a || !stack_b)
		return (1);
	if (ft_firstinit(stack_a, argv, argc))
		ft_sort(stack_a, stack_b);
	else
		ft_error("Error\n");
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
