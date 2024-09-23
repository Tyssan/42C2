/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:45:45 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/23 17:18:16 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
/*int_max int_min*/
# include <stdbool.h>
/*bool variable*/
# include <unistd.h>
/*write, read*/
# include <stdlib.h>
/*malloc, free, exit*/
# include "../src/libft/include/libft.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// init_a_to_b.c
void			init_nodes_a(t_stack *a, t_stack *b);
void			set_cheapest(t_stack *stack);
void			cost_analysis_a(t_stack *a, t_stack *b);
void			set_target_a(t_stack *a, t_stack *b);
void			current_index(t_stack *stack);

// init_b_to_a.c
void			init_nodes_b(t_stack *a, t_stack *b);
void			move_b_to_a(t_stack **a, t_stack **b);
void			set_target_b(t_stack *a, t_stack *b);

// stack_init.c
bool			ft_check_duplicate(t_stack *stack, int value);
long long		ft_check_errors(t_stack *stack, char *arg);
bool			ft_put_nbr_in_new_node(t_stack **stack, int n);
bool			ft_firstinit(t_stack **stack, char **argv);
void			ft_push_prep(t_stack **stack, t_stack *top_node, char s_name);

// stack_utils.c
bool			ft_stack_sorted(t_stack *stack);
t_stack			*ft_find_last_node(t_stack *stack);
unsigned int	ft_stack_len(t_stack *stack);
t_stack			*ft_smallest_node(t_stack *stack);
t_stack			*ft_biggest_node(t_stack *stack);

// ope_ .c
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **b, t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			ra(t_stack **a);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);

// sort_stacks.c
void			ft_sort_stacks(t_stack **a, t_stack **b);
void			min_on_top(t_stack **a);
void			move_a_to_b(t_stack **a, t_stack **b);
void			rr_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void			r_both(t_stack **a, t_stack **b, t_stack *cheapest_node);

// sort.c
t_stack			*ft_get_cheapest(t_stack *stack);
void			ft_sort_three(t_stack **a);
void			ft_sort(t_stack **a, t_stack **b);

// stop.c
void			ft_free_stack(t_stack **stack);
void			ft_free_split(char **split_argv);

#endif
