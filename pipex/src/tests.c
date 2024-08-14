/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:00:41 by tbrunier          #+#    #+#             */
/*   Updated: 2024/08/13 18:00:41 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	fd;
	int	stdout_backup;
	int	i;

	i = 0;
	stdout_backup = dup(STDOUT_FILENO);
	fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	if (access("example.txt", W_OK) == -1)
	{
		printf("I don't have permission to use fd, stopping...\n");
		return (0);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	write(1, "1 = ", 4);
	while (av[1][i])
	{
		write(1, &av[1][i], 1);
		i++;
	}
	dup2(stdout_backup, STDOUT_FILENO);
	close(stdout_backup);
	write(1, "2 = ", 4);
	while (i >= 0)
	{
		write(1, &av[1][i], 1);
		i--;
	}
	return (0);
}
