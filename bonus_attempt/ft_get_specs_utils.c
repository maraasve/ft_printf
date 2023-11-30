/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_specs_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:45:45 by marieke           #+#    #+#             */
/*   Updated: 2023/11/14 14:14:20 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	put_spaces(int start, int end)
{
	while (start < end)
	{
		write(1, "a", 1);
		start++;
	}
	return (start);
}

int	put_zeros(int start, int end)
{
	while (start < end)
	{
		write(1, "0", 1);
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
