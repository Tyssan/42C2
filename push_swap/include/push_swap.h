/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:45:45 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/12 19:01:55 by tbrunier         ###   ########.fr       */
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

// actions.c
void	ft_swap(t_stack *stack, char a_b);
void	ft_rotate(t_stack *stack, char a_b);
void	ft_reverse_rotate(t_stack *stack, char a_b);
void	ft_push_b(t_stack *stack_a, t_stack *stack_b);
void	ft_push_a(t_stack *stack_a, t_stack *stack_b);

// init.c
t_stack	*ft_allocate_stack(void);
int		ft_check_duplicate(t_stack *stack, int value);
int		ft_is_valid_int(char *str);
int		ft_check_errors(t_stack *stack_a, char *arg);
int		ft_firstinit(t_stack *stack_a, char **argv, int count);

// main.c
void	ft_error(const char *message);

// sort.c
void	ft_sort_small(t_stack *stack_a);
void	ft_sort_medium(t_stack *stack_a, t_stack *stack_b);
int		ft_get_max(t_stack *stack);
void	ft_radix_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_sort(t_stack *stack_a, t_stack *stack_b);

// stop.c
int		ft_pop(t_stack *stack);
void	ft_push(t_stack *stack, int value);
void	ft_free_stack(t_stack *stack);

#endif
