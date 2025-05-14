/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:12:37 by tbrunier          #+#    #+#             */
/*   Updated: 2024/03/29 19:12:37 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

int	get_next_line(int fd, char **line)
{
	static t_list	*stash = NULL;
	char			*newline;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, &line, 0) < 0)
		return (0);
	newline = NULL;
	read_and_stash(fd, &stash);
	if (stash == NULL)
		return (0);
	extract_line(stash, &newline);
	clean_stash(&stash);
	if (newline[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(newline);
		return (0);
	}
	*line = newline;
	return (1);
}

void	read_and_stash(int fd, t_list **stash)
{
	char	*buf;
	ssize_t	readed;

	readed = 1;
	while (found_new_line(*stash) == 0 && readed != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		readed = read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && readed == 0) || readed == -1)
		{
			free(buf);
			return ;
		}
		buf[readed] = '\0';
		add_to_stash(stash, buf, readed);
		free(buf);
	}
}

void	add_to_stash(t_list **stash, char *buf, ssize_t readed)
{
	int		i;
	t_list	*lastnode;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buf[i] && i < readed)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	lastnode = get_last_node(*stash);
	lastnode->next = new_node;
}

void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	generate_line(line, stash);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*clean;
	int		i;
	int		j;

	clean = malloc(sizeof(t_list));
	if (clean == NULL)
		return ;
	i = 0;
	clean->next = NULL;
	last = get_last_node(*stash);
	while (last->content[i] != '\0' && last->content[i] != '\n')
		i++;
	if (last->content != NULL && last->content[i] == '\n')
		i++;
	clean->content = malloc(sizeof(char)
			* ((ft_strlen(last->content) - i) + 1));
	if (clean->content == NULL)
		return ;
	j = 0;
	while (last->content[i] != '\0')
		clean->content[j++] = last->content[i++];
	clean->content[j] = '\0';
	free_stash(*stash);
	*stash = clean;
}
