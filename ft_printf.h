/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:26:45 by marieke           #+#    #+#             */
/*   Updated: 2023/11/04 17:38:19 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

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
} t_flags;



int	ft_printf(const char *string, ...);

#endif