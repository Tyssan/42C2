/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:04:58 by tbrunier          #+#    #+#             */
/*   Updated: 2024/08/06 16:04:58 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	res;

	i = 0;
	while(s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i])
		i++;
	}
	return (s1[i] - s2[i]);
}

int	main(int argc, char argv)
{
	int	res;

	if (argc == 3)
		res = ft_strcmp(argv[1], argv[2]);
	printf("%d\n", res);
	return (0);
}
