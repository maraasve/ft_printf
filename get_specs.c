/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:30:31 by marieke           #+#    #+#             */
/*   Updated: 2023/11/09 17:01:18 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_char(char c, t_flags *tabs)
{
	char	*s;
	int		len;
	int		i;

	len = tabs->width;
	if (!tabs->width)
		len = 1;
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	i = 0;
	while(tabs->width && !tabs->left_align && i < len - 1)
	{
		s[i] = ' ';
		i++;
	}
	s[i] = c;
	i++;
	while(tabs->left_align && i < len)
	{
		s[i] = ' ';
		i++;
	}
	s[len] = '\0';
	tabs->len = len;
	return (s);
}
