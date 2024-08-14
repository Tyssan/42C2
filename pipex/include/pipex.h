/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:18:01 by tbrunier          #+#    #+#             */
/*   Updated: 2024/07/17 19:18:01 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*system calls like pid_t*/
# include <sys/types.h>
/*write, read, close, access, pipe, dup, dup2, execve, fork*/
# include <unistd.h>
/*malloc, free, exit*/
# include <stdlib.h>
/*open, unlink*/
# include <fcntl.h>
/*waitpid, wait*/
# include <sys/wait.h>
/*strerror*/
# include <string.h>
/*to perror*/
# include <stdio.h>
/*errno global variable for perror*/
# include <errno.h>

typedef struct s_pipex
{
	pid_t	pid1;/*contains the pid of the first fork*/
	pid_t	pid2;/*contains the pid of the second fork*/
	int		tube[2];/*tube[0] and tube[1], todo*/
	int		infile;/*infile.txt FD*/
	int		outfile;/*outfile.txt FD*/
	char	*paths;/*contains whats after enmv PATH=*/
	char	**cmd_paths;/*lists of strings of commands paths*/
	char	**cmd_args;/*todo*/
	char	*cmd;/*todo*/
}	t_pipex;

/*errors.c*/
int		msg(char *error_code);
void	msg_error(char *error_code);

/*childs.c*/
void	first_child(pipex, argv, envp);
void	second_child(pipex, argv, envp);

/*pipex.c*/
char	*find_path(char **envp);


#endif
