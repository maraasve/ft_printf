/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_specs_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:45:45 by marieke           #+#    #+#             */
/*   Updated: 2023/11/10 17:48:55 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	put_spaces(char *str, int start, int end)
{
	while (start < end)
	{
		str[start] = 'a';
		start++;
	}
	return (start);
}

int	put_zeros(char *str, int start, int end)
{
	while (start < end)
	{
		str[start] = '0';
		start++;
	}
	return (start);
}

size_t	ft_itoa_mod(char	*str, size_t num)
{
	size_t	digit_count;
	size_t	i;

	if (num == 0)
	{
		str[0] = '0';
		return (1);
	}
	digit_count = ft_countdigits(num);
	i = digit_count;
	while (num > 0)
	{
		str[i - 1] = num % 10 + '0';
		num /= 10;
		i--;
	}
	return (digit_count);
}
