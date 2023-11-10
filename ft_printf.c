/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:26:09 by marieke           #+#    #+#             */
/*   Updated: 2023/11/09 18:18:44 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	write_to_buffer(const char *string, size_t len, char *buffer)
{
	if (!string)
		return (0);
	if (len == 0)
		return (1);
	write(1, string, len);
	return (1);
}

int	convert_specifiers(char c, char *buffer, va_list args, t_flags *tabs)
{
	if (c == '%')
	{
		if(!write_to_buffer("%", 1, buffer))
			return (0);
	}
	else if (c == 'c')
	{
		if (!write_to_buffer(get_char(va_arg(args, int), tabs), tabs->len, buffer))
			return (0);
	}
 	else if (c == 's')
	{
		if (!write_to_buffer(get_string(va_arg(args, char *), tabs), tabs->len, buffer))
			return (0);
	}
/*	else if (c == 'd' || c == 'i')
	{
		if (!write_to_buffer(get_int(va_arg(args, int), tabs), tabs->len, buffer))
			return (0);
	}
	else if (c == 'x')
	{
		if (!write_to_buffer(get_hex_low(va_arg(args, int), tabs), tabs->len, buffer))
			return (0);
	}
	else if (c == 'X')
	{
		if (!write_to_buffer(get_hex_up(va_arg(args, int), tabs), tabs->len, buffer))
			return (0);
	}
	else if (c == 'p')
	{
		if (!write_to_buffer(get_ptr(va_arg(args, int), tabs), tabs->len, buffer))
			return (0);
	}
	else if (c == 'u')
	{
		if (!write_to_buffer(get_u_int(va_arg(args, int), tabs), tabs->len, buffer))
			return (0);
	}*/
	return (1); 
}

int save_flags_to_tabs(char *string, va_list args, t_flags *tabs, char *buffer)
{
	int i;

	set_flags_to_zero(tabs);
	tabs->width = get_width(string);
	tabs->precision = get_precision(string);
	i = 0;
	if (string[i] == '%')
		i++;
	while(ft_strchr(FLAGS, string[i]) || ft_isdigit(string[i]))
	{
		if (string[i] == '#')
			tabs->hash = 1;
		if (string[i] == '0')
			tabs->zero_pad = 1;
		if (string[i] == '-')
			tabs->left_align = 1;
		if (string[i] == '+')
			tabs->sign = 1;
		if (string[i] == ' ')
			tabs->space = 1;
		if (string[i] == '*')
			tabs->asterisk = 1;
		i++;
	}
	return (i);
}

int	read_string(const char *string, va_list args, t_flags *tabs, char *buffer)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			if (!write_to_buffer(&string[start], (i - start), buffer))
				return (0);
			i += save_flags_to_tabs((char *)&string[i], args, tabs, buffer);
			if (!convert_specifiers(string[i], buffer, args, tabs))
				return (0);
			i++;
			start = i;
		}
		else
			i++;
	}
	if (!write_to_buffer(&string[start], (i - start), buffer))
				return (0);
	return (1);
}

int	ft_printf(const char *string, ...)
{
	va_list		args;
	t_flags		*tabs;
	int			len;
	char		*buffer;

	va_start(args, string);
	buffer = ft_strdup("");
	if (!buffer)
		return (-1);
	tabs = (t_flags *)malloc(sizeof(t_flags));
	if (!tabs)
		return (-1);
	if (!read_string(string, args, tabs, buffer))
		return (-1);
	len = ft_strlen(buffer);
	write(1, buffer, len);
	free(buffer);
	va_end(args);
	return (len);
}
int main(void)
{
	ft_printf("--%s--", "123456789");
}