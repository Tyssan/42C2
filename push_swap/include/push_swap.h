/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:45:45 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/08 16:45:45 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
/*write, read*/
# include <stdlib.h>
/*malloc, free, exit*/
# include "../src/libft/include/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

// init.c
t_stack	*ft_allocate_stack(int size);
int		ft_firstinit(t_stack *stack_a, char **argv, int count);
int		ft_pop(t_stack *stack);
void	ft_push(t_stack *stack, int value);
void	ft_free_stack(t_stack *stack);

// main.c

// sort.c
void	ft_sort_small(t_stack *stack_a);
void	ft_sort_medium(t_stack *stack_a, t_stack *stack_b);
int		ft_get_max(t_stack *stack);
void	ft_radix_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_sort(t_stack *stack_a, t_stack *stack_b);

#endif
