/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:51:22 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/23 17:16:04 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_prep(t_stack **stack, t_stack *top_node, char s_name)
{
	while (*stack != top_node)
	{
		if (s_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (s_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

bool	ft_check_duplicate(t_stack *stack, int value)
{
	if (!stack)
		return (false);
	while (stack)
	{
		if (stack->nbr == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}

long long	ft_check_errors(t_stack *stack, char *arg)
{
	int			i;
	long long	value;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		return (LLONG_MAX);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (LLONG_MAX);
		i++;
	}
	value = ft_atoll(arg);
	if (value > INT_MAX || value < INT_MIN)
		return (LLONG_MAX);
	if (ft_check_duplicate(stack, value))
		return (LLONG_MAX);
	return (value);
}

bool	ft_put_nbr_in_new_node(t_stack **stack, int n)
{
	t_stack	*newnode;
	t_stack	*lastnode;

	if (!stack)
		return (false);
	newnode = malloc(sizeof(t_stack));
	if (!newnode)
		return (false);
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->nbr = n;
	newnode->cheapest = false;
	if (!(*stack))
	{
		*stack = newnode;
		newnode->prev = NULL;
	}
	else
	{
		lastnode = ft_find_last_node(*stack);
		lastnode->next = newnode;
		newnode->prev = lastnode;
	}
	return (true);
}

bool	ft_firstinit(t_stack **stack, char **argv)
{
	int			i;
	long long	value;

	i = 0;
	while (argv[i])
	{
		value = ft_check_errors(*stack, argv[i]);
		if (value == LLONG_MAX)
		{
			write(1, "Error\n", 6);
			return (false);
		}
		if (!ft_put_nbr_in_new_node(stack, value))
			return (false);
		i++;
	}
	return (true);
}
