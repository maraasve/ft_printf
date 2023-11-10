/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:30:31 by marieke           #+#    #+#             */
/*   Updated: 2023/11/09 23:41:10 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*get_char(char c, t_flags *tabs)
{
	char	*s;
	int		strlen;
	int		i;

	strlen = tabs->width;
	if (!tabs->width)
		strlen = 1;
	s = (char *)malloc(sizeof(char) * (strlen + 1));
	if (!s)
		return (NULL);
	i = 0;
	if(tabs->width && !tabs->left_align)
		put_spaces(s, i, strlen - 1);
	s[i] = c;
	i++;
	if(tabs->left_align)
		put_spaces(s, i, strlen);
	s[strlen] = '\0';
	tabs->len = strlen;
	return (s);
}

char	*get_string(char *old_str, t_flags *tabs)
{
	char	*new_str;
	int		total_len;
	int		strlen;
	int		i;

	strlen = ft_strlen(old_str);
	if (tabs->width < strlen && tabs->precision > strlen)
	{
		tabs->len = strlen;
		return (old_str);
	}
	if (tabs->precision && tabs->precision < strlen)
		strlen = tabs->precision;
	if (tabs->width > strlen)
		total_len = tabs->width;
	else
		total_len = strlen;
	new_str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!new_str)
		return (NULL);
	i = 0;	
	if (tabs->width > strlen && !tabs->left_align)
		i += put_spaces(new_str, i, total_len - strlen);
	ft_strlcpy(&new_str[i], old_str, strlen + 1);
	if (tabs->width > strlen && tabs->left_align)
		i += put_spaces(&new_str[strlen], i, total_len - strlen);
	tabs->len = total_len;
	return (new_str); 
}

char	*get_int(int num, t_flags *tabs)
{
	char	*s;
	int		num_len;
	int		total_len;
	int		i;

	num_len = ft_countdigits(ft_abs(num));
	if (tabs->precision < num_len)
		num_len = tabs->precision;
	if (num < 0 || tabs->sign || tabs->space)
		num_len++;
	if (tabs->width > num_len)
		total_len = tabs->width;
	else
		total_len = num_len;
	
	
}