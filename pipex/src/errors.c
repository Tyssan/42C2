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

#include "../include/pipex.h"
#include "./libft/include/libft.h"

int	msg(char *code)
{
	write(2, code, ft_strlen(code));
	return (1);
}

void	msg_error(char *code)
{
	perror(code);
	exit(1);
}
