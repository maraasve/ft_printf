/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:26:45 by marieke           #+#    #+#             */
/*   Updated: 2023/11/09 16:57:55 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#  define FLAGS "-0. #+"
#  define SPECIFIERS "cspdiuxX"

# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	width;
	int	precision;
	int	zero_pad;
	int	sign;
	int	left_align;
	int	space;
	int	hash;
	int	asterisk;
	int	len;
}	t_flags;

typedef struct s_buffer
{
	char	*buffer;
	int		size;
}	t_buffer;

int		ft_printf(const char *string, ...);
void	set_flags_to_zero(t_flags *tabs);
int		ft_strlen_until_next_spec(char *s);
int		get_width(char *string);
int		get_precision(char *string);
char	*get_char(char c, t_flags *tabs);
#endif