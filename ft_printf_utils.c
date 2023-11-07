/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:46:01 by maraasve          #+#    #+#             */
/*   Updated: 2023/11/07 17:46:15 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	set_flags_to_zero(t_flags *tabs)
{
	tabs->width = 0;
	tabs->precision = 0;
	tabs->zero_pad = 0;
	tabs->sign = 0;
	tabs->left_align = 0;
	tabs->space = 0;
	tabs->hash = 0;
	tabs->asterisk = 0;
	tabs->total_len = 0;
}

int	ft_strlen_until_next_spec(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_strchr(SPECIFIERS, s[i]))
		{
			return (i);
		}
		i++;
	}
	return (i);
}

int	get_width(char *string)
{
	int i;
	int width;

	i = 0;
	width = 0;
	while (ft_strchr(FLAGS, string[i]))
	{
		i++;
	}
	while (ft_isdigit(string[i]))
	{
		width = width * 10 + (string[i] - 48);
		i++;
	}
	return (width);
}

int	get_precision(char *string)
{
	int i;
	int precision;

	i = 0;
	precision = 0;
	while (ft_strchr(FLAGS, string[i]) || ft_isdigit(string[i]))
	{
		i++;
	}
	if (string[i] != '.')
		return (precision);
	else
		i++;
	while (ft_isdigit(string[i]))
	{
		precision = precision * 10 + (string[i] - 48);
		i++;
	}
	return (precision);
}
