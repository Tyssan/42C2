/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:51:22 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/12 17:31:10 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_allocate_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

int	ft_check_duplicate(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	ft_is_valid_int(char *str)
{
	long long	value;

	value = ft_atoll(str);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	return (1);
}

int	ft_check_errors(t_stack *stack_a, char *arg)
{
	int		j;
	int		value;

	j = 0;
	if (arg[j] == '-' || arg[j] == '+')
		j++;
	while (arg[j])
	{
		if (!ft_isdigit(arg[j]))
			ft_error("Error: Bad input value detected.\n");
		j++;
	}
	if (!ft_is_valid_int(arg))
		ft_error("Error: Value exceeds INT limits.\n");
	value = ft_atoi(arg);
	if (ft_check_duplicate(stack_a, value))
		ft_error("Error: Duplicate value detected.\n");
	return (1);
}

int	ft_firstinit(t_stack *stack_a, char **argv, int count)
{
	int		i;
	t_node	*new_node;

	i = 1;
	while (i < count)
	{
		if (!ft_check_errors(stack_a, argv[i]))
			return (0);
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			return (0);
		new_node->value = ft_atoi(argv[i]);
		new_node->next = stack_a->top;
		stack_a->top = new_node;
		stack_a->size++;
		i++;
	}
	return (1);
}
