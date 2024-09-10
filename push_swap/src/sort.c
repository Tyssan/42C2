/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:13:49 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/09 00:13:49 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_sort_small(t_stack *stack_a)
{
	int a = stack_a->top->value;
	int b = stack_a->top->next->value;
	int c = stack_a->top->next->next->value;

	if (a > b && b > c)
	{
	ft_swap(stack_a); // sa
	ft_reverse_rotate(stack_a); // rra
	}
	else if (a > b && b < c && a < c)
	ft_swap(stack_a); // sa
	else if (a > b && b < c && a > c)
		ft_rotate(stack_a); // ra
	else if (a < b && b > c && a < c)
		ft_reverse_rotate(stack_a); // rra
	else if (a < b && b > c && a > c)
	{
		ft_swap(stack_a); // sa
		ft_rotate(stack_a); // ra
	}
	return ;
}

void ft_sort_medium(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
	{
		ft_push(stack_b, ft_pop(stack_a)); // pb
	}
	ft_sort_small(stack_a); // Trier les 3 éléments restants
	while (stack_b->size > 0)
	{
		ft_push(stack_a, ft_pop(stack_b)); // pa
	}
	return ;
}

int ft_get_max(t_stack *stack)
{
	t_node *current;
	int max;

	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

void ft_radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int max;
	int exp; // Exposant pour les chiffres (1, 10, 100, ...)
	int i;

	max  = ft_get_max(stack_a);
	exp = 1;
	while (max / exp > 0)
	{
		i = 0;
		while (i < stack_a->size)
		{
			int value = stack_a->top->value;
			if ((value / exp) % 10 == 0)
				ft_push(stack_b, ft_pop(stack_a)); // pb
			else
				ft_rotate(stack_a); // ra
			i++;
		}
		while (stack_b->size > 0)
			ft_push(stack_a, ft_pop(stack_b)); // pa
		exp *= 10;
	}
	return ;
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		if (stack_a->top->value > stack_a->top->next->value)
			ft_swap(stack_a); // sa
	}
	if (stack_a->size <= 3)
		ft_sort_small(stack_a);
	else if (stack_a->size <= 5)
		ft_sort_medium(stack_a, stack_b);
	else
		ft_radix_sort(stack_a, stack_b);
	return ;
}
