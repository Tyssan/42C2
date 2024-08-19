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
/*open, unlink, exit, EXIT_FAILURE macro, EXIT_SUCCES macro*/
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
	char	**cmd_args;/*command parameters*/
	char	*cmd;/*final command to use in execve*/
}	t_pipex;

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
