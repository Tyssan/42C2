/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:26:51 by tbrunier          #+#    #+#             */
/*   Updated: 2024/07/03 13:26:51 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"

void	bit_handler(int signum)
{
	static int	bits_done;
	static int	current_char;
	int			bit;

	if (signum == SIGUSR2)
		bit = 0;
	else if (signum == SIGUSR1)
		bit = 1;
	else
	{
		ft_printf("SIGNAL ERROR");
		return ;
	}
	current_char = (current_char << 1) + bit;
	bits_done++;
	if (bits_done == 8)
	{
		if (current_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &current_char, 1);
		bits_done = 0;
		current_char = 0;
	}
	return ;
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, bit_handler);
	signal(SIGUSR2, bit_handler);
	while (1)
		pause();
	return (0);
}
