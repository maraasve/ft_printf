/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:30:31 by marieke           #+#    #+#             */
/*   Updated: 2023/11/10 18:00:07 by maraasve         ###   ########.fr       */
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

	if (!old_str)
	{
		new_str = (char *)malloc(sizeof(char) * 7);
		if (!new_str)
			return (NULL);
		ft_strlcpy (new_str, "(null)", 7);
		return (new_str);
	}
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
	new_str[i] = '\0';
	tabs->len = total_len;
	return (new_str); 
}

char	*get_int(int num, t_flags *tabs)
{
	char	*s;
	int		num_len;
	int		total_len;
	int		i;

	if (num == 0)
		num_len = 1;
	else
		num_len = ft_countdigits(ft_abs(num));
	if (num < 0 || tabs->sign || tabs->space)
		num_len++;
	if (tabs->width > num_len && tabs->precision < tabs->width)
		total_len = tabs->width;
	else if (tabs->precision > num_len && tabs->precision > tabs->width)
	{
		total_len = tabs->precision;
		if (tabs->sign || tabs->space || num < 0)
			total_len++;
	}
	s = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!s)
		return (NULL);
	i = 0;
	if (tabs->width > num_len && tabs->width > tabs->precision && !tabs->zero_pad && !tabs->left_align)
		i += put_spaces(s, i, tabs->width - ft_biggestnum(num_len, tabs->precision));
	else if (tabs->width > num_len && tabs->width > tabs->precision && tabs->zero_pad && !tabs->left_align)
		i += put_zeros(s, i, tabs->width - ft_biggestnum(num_len, tabs->precision));
	if (tabs->precision > num_len)
		i = put_zeros(s, i, total_len - num_len);
	if (num > 0 && tabs->sign)
	{
		s[i] = '+';
		i++;
	}
	else if (num > 0 && tabs->space)
		i += put_spaces(s, i, i + 1);
	else if (num < 0)
	{
		s[i] = '-';
		i++;
	}
	i += ft_itoa_mod(&s[i], ft_abs(num));
	if (tabs->width > ft_biggestnum(num_len, tabs->precision) && tabs->left_align)
		i += put_spaces(s, i, total_len);
	tabs->len = total_len;
	return (s);
}
