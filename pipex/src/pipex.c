/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:02:38 by tbrunier          #+#    #+#             */
/*   Updated: 2024/07/17 20:02:38 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "./libft/include/libft.h"

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4))
	{
		i++;
	}
	return (envp[i] + 5);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
	{
		return (msg(INPUT_ERROR));
	}
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
	{
		msg_error(INFILE_ERROR);
	}
	pipex.outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.outfile < 0)
	{
		msg_error(ERR_OUTFILE);
	}
	if (pipe(pipex.tube) < 0)
	{
		msg_error(ERR_PIPE);
	}
	pipex.paths = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
	{
		first_child(pipex, argv, envp);
	}
	pipex.pid2 = fork();
	if (pipex_pid2 == 0)
	{
		second_child(pipex, argv, envp);
	}
	close_pipes(pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	parent_free(&pipex);
	return (0);
}
