/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:58:28 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/18 11:24:45 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = -1;
	while (s[res])
	{
		while(reject[++i])
		{
			if (s[res] == reject[i])
				return (res);
		}
		i = -1;
		res++;
	}
	return (res);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	s[] = "oui bonjour";
	const char	reject[] = "z";

	printf("%ld\n", ft_strcspn(s, reject));
	printf("%ld\n", strcspn(s, reject));
	return (0);
}*/