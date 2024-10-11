/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 08:45:56 by tbrunier          #+#    #+#             */
/*   Updated: 2024/04/04 08:45:56 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/get_next_line.h"

int	found_new_line(t_list *stash)
{
	int		i;
	t_list	*current;

	if (stash == NULL)
		return (0);
	current = get_last_node(stash);
	i = 0;
	while (current->content[i] != '\0')
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*get_last_node(t_list *stash)
{
	t_list	*current;

	current = stash;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	generate_line(char **line, t_list *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash != NULL)
	{
		i = 0;
		while (stash->content[i] != '\0')
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*buffer;

	current = stash;
	while (current != NULL)
	{
		free(current->content);
		buffer = current->next;
		free(current);
		current = buffer;
	}
}

size_t	ftstrlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
