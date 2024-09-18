/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:39:15 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/12 17:19:01 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

	if (!stack)
		return ;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
	return ;
}

void	ft_free_stack(t_stack *stack)
{
	while (stack->top != NULL)
		ft_pop(stack);
	free(stack);
	return ;
}
