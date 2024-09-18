/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:13:24 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/12 19:01:49 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_stack *stack, char a_b)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = temp;
	if (a_b == 'a')
		write(1, "sa\n", 3);
	else if (a_b == 'b')
		write(1, "sb\n", 3);
	return ;
}

// Fonction pour faire tourner la pile vers le haut
void	ft_rotate(t_stack *stack, char a_b)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	last->next = first;
	first->next = NULL;
	if (a_b == 'a')
		write(1, "ra\n", 3);
	else if (a_b == 'b')
		write(1, "rb\n", 3);
	return ;
}

// Fonction pour faire tourner la pile vers le bas
void	ft_reverse_rotate(t_stack *stack, char a_b)
{
	t_node	*last;
	t_node	*second_last;

	if (stack->size < 2)
		return ;
	last = stack->top;
	while (last->next->next)
		last = last->next;
	second_last = last;
	last = last->next;
	second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
	if (a_b == 'a')
		write(1, "rra\n", 4);
	else if (a_b == 'b')
		write(1, "rrb\n", 4);
	return ;
}

// Fonction pour ajouter un élément au sommet de la pile B
void	ft_push_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 0)
		return ;
	ft_push(stack_b, ft_pop(stack_a));
	write(1, "pb\n", 3);
	return ;
}

// Fonction pour ajouter un élément au sommet de la pile A
void	ft_push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size == 0)
		return ;
	ft_push(stack_a, ft_pop(stack_b));
	write(1, "pa\n", 3);
	return ;
}
