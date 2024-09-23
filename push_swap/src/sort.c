/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:13:49 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/23 17:14:08 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	ft_sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = ft_biggest_node(*a);
	if (biggest_node == *a)
		ra(a);
	else if (biggest_node == (*a)->next)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
	return ;
}

void	ft_sort(t_stack **a, t_stack **b)
{
	unsigned int	stack_len;

	stack_len = ft_stack_len(*a);
	if (stack_len == 2)
		sa(a);
	else if (stack_len == 3)
		ft_sort_three(a);
	else
		ft_sort_stacks(a, b);
	return ;
}
