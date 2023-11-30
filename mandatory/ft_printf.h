/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:43:00 by maraasve          #+#    #+#             */
/*   Updated: 2023/11/28 14:54:50 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef BASE16
#  define BASE16_LOW "0123456789abcdef"
# endif

# ifndef BASE16
#  define BASE16_UP "0123456789ABCDEF"
# endif

# include <stdarg.h>

//ft_printf.c
int	ft_printf(const char *string, ...);
int	convert_specifiers(const char *string, va_list args);

//ft_printf_utils.c
int	ft_putpartstr(const char *s, int len);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	num_len(unsigned int n);
int	ft_putnbr(int n);

//ft_printf_utils2.c
int	ft_putuint(unsigned int n);
int	ft_putlong_base(unsigned long n, char *basestr, int basenum);
int	ft_write_ptr(void *ptr);

#endif