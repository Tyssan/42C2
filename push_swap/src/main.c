/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:49:10 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/23 02:17:17 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split_argv;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	split_argv = NULL;
	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv)
			return (1);
		argv = split_argv;
	}
	stack_a = NULL;
	stack_b = NULL;
	if (ft_firstinit(&stack_a, argv + 1))
		if (!ft_stack_sorted(stack_a))
			ft_sort(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	if (split_argv)
		ft_free_split(split_argv);
	return (0);
}
