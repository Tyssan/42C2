/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:57:45 by tbrunier          #+#    #+#             */
/*   Updated: 2024/07/03 13:57:45 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <signal.h>
# include <stdint.h>

/*ft_printf.c*/
int				ft_printf(const char *format, ...);
int				ft_formats(va_list args, const char format);
int				ft_print_char(int c);
int				unsigned_de_merde(long num);

/*ft_printf_utils.c*/
int				ft_print_nbr(int nbr);
int				ft_print_str(char *str);

/*ft_print_hex.c*/
int				ft_print_hex(unsigned int hexvalue, const char format);
void			ft_write_hex(unsigned int hexvalue, const char format);
unsigned int	ft_count_hex(unsigned int hexvalue);

/*ft_print_unsigned.c*/
int				ft_print_unsigned(unsigned int n);
char			*ft_uitoa(unsigned int n);
int				ft_unumlen(unsigned int n);

/*ft_print_ptr.c*/
int				ft_print_ptr(unsigned long long ptr);
void			ft_write_ptr(uintptr_t hexvalue);
unsigned int	ft_count_ptr(uintptr_t hexvalue);

/*libft*/
int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);
char			*ft_itoa(int n);
size_t			ft_numlen(int n);
void			ft_putchar_fd(char c, int fd);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);

/*client*/
int				args_check(int arg_count, char **args);
void			send_bit(int pid, unsigned char current_char);

/*server*/
void			bit_handler(int signum);

#endif
