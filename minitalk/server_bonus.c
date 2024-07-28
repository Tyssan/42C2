/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:07:21 by tbrunier          #+#    #+#             */
/*   Updated: 2024/07/08 12:07:21 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minitalk_bonus.h"

void	bit_handler(int signum, siginfo_t *info, void *context)
{
	static int	bits_done;
	static int	current_char;
	int			bit;

	(void)context;
	if (signum == SIGUSR2)
		bit = 0;
	else if (signum == SIGUSR1)
		bit = 1;
	current_char = (current_char << 1) + bit;
	bits_done++;
	if (bits_done == 8)
	{
		if (current_char == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
			write(1, &current_char, 1);
		bits_done = 0;
		current_char = 0;
	}
	if (signum == SIGUSR1 || signum == SIGUSR2)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &bit_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("Server PID: %u\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
