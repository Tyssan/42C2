/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:53:18 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/23 17:18:16 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	r_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rr_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = ft_get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		r_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rr_both(a, b, cheapest_node);
	ft_push_prep(a, cheapest_node, 'a');
	ft_push_prep(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

void	min_on_top(t_stack **a)
{
	while ((*a)->nbr != ft_smallest_node(*a)->nbr)
	{
		if (ft_smallest_node(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	ft_sort_stacks(t_stack **a, t_stack **b)
{
	unsigned int	len_a;

	len_a = ft_stack_len(*a);
	if (len_a-- > 3 && !ft_stack_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !ft_stack_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !ft_stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	ft_sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
