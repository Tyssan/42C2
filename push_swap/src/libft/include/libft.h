/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:06:46 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/23 02:14:44 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
/*LLONG_MAX, LLONG_MIN*/
# include <stddef.h>
/*size_t*/
# include <stdlib.h>
/*malloc, free*/

int			ft_atoi(const char *nptr);
long long	ft_atoll(const char *nptr);
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *str);

#endif
