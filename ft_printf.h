/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:26:45 by marieke           #+#    #+#             */
/*   Updated: 2023/11/06 17:43:50 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#  define FLAGS "-0. #+"
#  define SPECIFIERS "cspdiuxX"

# include <stdarg.h>

typedef struct s_flags
{
	int	width;
	int	precision;
	int	zero_pad;
	int	point;
	int	sign;
	int	dash;
	int	total_len;
	int	space;
	int	hash;
}	t_flags;

typedef struct s_buffer
{
	char	*buffer;
	int		size;
}	t_buffer;

int	ft_printf(const char *string, ...);
void	set_flags_to_zero(t_flags *tabs);

#endif