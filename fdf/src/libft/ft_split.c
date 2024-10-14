/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:24:45 by tbrunier          #+#    #+#             */
/*   Updated: 2024/01/12 15:24:45 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	count_words(char const *str, char c)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

unsigned int	ft_strlen_sep(char const *str, char c)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

char	*get_word(char const *str, char c)
{
	char			*word;
	unsigned int	i;

	i = 0;
	word = malloc(sizeof(char) * (ft_strlen_sep(str, c) + 1));
	if (!word)
		return (NULL);
	while (i < ft_strlen_sep(str, c))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	i;

	i = 0;
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
			tab[i++] = get_word(s, c);
		while (*s != '\0' && *s != c)
			s++;
	}
	tab[i] = 0;
	return (tab);
}
