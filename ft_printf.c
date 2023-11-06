/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:26:09 by marieke           #+#    #+#             */
/*   Updated: 2023/11/04 17:37:02 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *string, ...)
{
	int		length;
	int 	buffer_size;
	int		i;
	va_list args;
	t_flags	tabs;
	
	va_start(args, string);
	
	i = 0;
	length = 0;
	while(string[i] != '\0')
	{
		if (string[i] == '%')
			length += check_format(tabs, );
		else
			length++;
	}
}