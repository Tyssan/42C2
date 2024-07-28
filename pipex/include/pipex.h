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

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

/*errors.c*/
int		msg(char *error_code);
void	msg_error(char *error_code);


#endif
