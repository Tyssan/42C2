/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 05:25:10 by tbrunier          #+#    #+#             */
/*   Updated: 2024/07/23 05:25:10 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/pipex.h>
#include <./libft/include/libft.h>

int	msg(char *error_code)
{
	write(2, error_code, ft_strlen(error_code));
	return (1);
}

void	msg_error(char *error_code)
{
	perror(error_code);
	exit(1);
}
