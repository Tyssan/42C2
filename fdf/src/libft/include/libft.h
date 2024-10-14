/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:06:46 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/14 03:28:19 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//LIBFT
# include <stddef.h>
//size_t variable

int		ft_atoi(const char *nptr);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//GNL
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

/*get_next_line.c*/
char	*get_next_line(int fd);
void	read_and_stash(int fd, t_list **stash);
void	add_to_stash(t_list **stash, char *buf, ssize_t readed);
void	extract_line(t_list *stash, char **line);
void	clean_stash(t_list **stash);

/*get_next_line_utils.c*/
int		found_new_line(t_list *stash);
t_list	*get_last_node(t_list *stash);
void	generate_line(char **line, t_list *stash);
void	free_stash(t_list *stash);

#endif
