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

# include <sys/types.h>
/*system calls like pid_t*/
# include <unistd.h>
/*write, read, close, access, pipe, dup, dup2, execve, fork*/
# include <stdlib.h>
/*malloc, free, exit*/
# include <fcntl.h>
/*open, unlink, exit, EXIT_FAILURE macro, EXIT_SUCCES macro*/
# include <sys/wait.h>
/*waitpid, wait*/
# include <string.h>
/*strerror*/
# include <stdio.h>
/*to perror*/
# include <errno.h>
/*errno global variable for perror*/

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
/*
pid1: contains the pid of the first fork
pid2: contains the pid of the second fork
tube[2]: tube[0] and tube[1]
infile.txt FD
outfile.txt FD
contains whats after enmv PATH=
lists of strings of commands paths
command parameters
final command to use in execve
*/

# define INFILE_ERROR "Infile"
# define OUTFILE_ERROR "Outfile"
# define INPUT_ERROR "Invalid number of arguments.\n"
# define PIPE_ERROR "Pipe"
# define CMD_ERROR "Command not found\n"

/*errors.c*/
int		msg(char *code);
void	msg_error(char *code);

/*free.c*/
void	child_free(t_pipex *pipex);
void	parent_free(t_pipex *pipex);

/*childs.c*/
char	*get_cmd(char **paths, char *cmd);
void	first_child(t_pipex pipex, char **argv, char **envp);
void	second_child(t_pipex pipex, char **argv, char **envp);

/*pipex.c*/
char	*find_path(char **envp);

#endif
