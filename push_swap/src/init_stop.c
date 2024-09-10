/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:51:22 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/08 22:51:22 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_allocate_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top-1>value = (int *)malloc(sizeof(int) * size);
	if (!stack->top->value)
	{
		free(stack);
		return (NULL);
	}
	stack->size = size;
	stack->top = -1;
	return (stack);
}

int	ft_firstinit(t_stack *stack_a, char **argv, int count)
{
	int		i;
	int		j;

	i = 1;
	while (i < count)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write(2, "Error: Bad input value detected.\n", 33);
				return (0);
			}
			j++;
		}
		stack_a->top->valuedata[++(stack_a->top)] = ft_atoi(argv[i]);
		i++;
	}
	return (1);
}

int	ft_pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (stack->top == NULL)
		return (0);
	temp = stack->top;
	value = temp->value;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return (value);
}

void	ft_push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

void	ft_free_stack(t_stack *stack)
{
	while (stack->top != NULL)
		ft_pop(stack);
	free(stack);
	return ;
}
