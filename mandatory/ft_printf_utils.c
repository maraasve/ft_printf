/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:21:00 by marieke           #+#    #+#             */
/*   Updated: 2023/11/30 17:47:03 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_putpartstr(const char *s, int len)
{
	if (!len)
		return (0);
	write(1, s, len);
	return (len);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
		return (write(1, "(null)", 6));
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	num_len(unsigned long n)
{
	int				len;

	len = 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_putnbr(int nb)
{
	int				len;

	len = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		len++;
	}
	if (nb > 9 || nb < -9)
		len += ft_putnbr(ft_abs(nb / 10));
	ft_putchar((ft_abs(nb % 10)) + '0');
	return (len + 1);
}
