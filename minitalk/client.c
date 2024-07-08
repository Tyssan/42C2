/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:26:48 by tbrunier          #+#    #+#             */
/*   Updated: 2024/07/03 13:26:48 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"

int	args_check(int arg_count, char **args)
{
	int	i;

	i = 0;
	if (arg_count != 3)
	{
		ft_printf("\nERROR: invalid arguments. Usage: ./client PID <STRING>\n");
		return (0);
	}
	if (*args[2] == 0)
	{
		ft_printf("\nERROR: invalid message (empty)\n");
		return (0);
	}
	while (args[1][i] != '\0')
	{
		if (!(ft_isdigit(args[1][i])))
		{
			ft_printf("\nERROR: invalid PID\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	send_bit(int pid, unsigned char current_char)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((current_char >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(420);
		i--;
	}
	return ;
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (!args_check(argc, argv))
		return (0);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
		send_bit(pid, argv[2][i++]);
	send_bit(pid, '\0');
	return (0);
}
