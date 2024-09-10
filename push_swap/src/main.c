/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:49:10 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/08 16:49:10 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	if (argc < 3)
	{
		write(2, "not enough inputs, 2 ints min.\n", 31);
		return (1);
	}
	stack_a = ft_allocate_stack(argc);
	stack_b = ft_allocate_stack(0);
	if (!stack_a || !stack_b)
		return (1);
	if (ft_firstinit(stack_a, argv, argc))
	{
		ft_sort(stack_a, stack_b);
	}
	else
	{
		write(2, "error: bad input value detected.\n", 33);
	}
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
