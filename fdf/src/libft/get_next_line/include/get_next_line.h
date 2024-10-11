/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 08:43:07 by tbrunier          #+#    #+#             */
/*   Updated: 2024/04/04 08:43:07 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
void	read_and_stash(int fd, t_list **stash);
void	add_to_stash(t_list **stash, char *buf, ssize_t readed);
void	extract_line(t_list *stash, char **line);
void	clean_stash(t_list **stash);
int		found_new_line(t_list *stash);
t_list	*get_last_node(t_list *stash);
void	generate_line(char **line, t_list *stash);
void	free_stash(t_list *stash);
size_t	ftstrlen(char *str);

#endif
