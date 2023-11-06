/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:26:09 by marieke           #+#    #+#             */
/*   Updated: 2023/11/06 18:07:39 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	write_to_buffer(const char *string, size_t len, char *buffer)
{
	
}

int	check_spec_and_flags(char *string, va_list args, t_flags *tabs, char *buffer)
{
	int i;

	set_flags_to_zero(tabs);
	if (string[1] == '%')
	{
		write_to_buffer(string, 1, buffer);
		return (2);
	}
	i = 0;
	//CHECK width
	//CHECK zero
	while (!ft_strchr(string[i], SPECIFIERS))
	{
		if(ft_strchr(string[i], FLAGS))
			add_flag_to_tabs(tabs, string[i]);
		i++;
	}
	parse_specifier(string[i])
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
			if (!write_to_buffer(&string[start], (i - 1 - start), buffer))
				return (-1);
			i += check_spec_and_flags(&string[i], args, tabs, buffer);
			start = i;
		}
		else
			i++;
	}
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
	len = read_string(string, args, tabs, buffer);
	return (len);
}
