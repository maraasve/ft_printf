/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:06:22 by maraasve          #+#    #+#             */
/*   Updated: 2025/07/04 20:35:21 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

int	ft_putuint(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
		len += ft_putuint(nb / 10);
	ft_putchar_fd((nb % 10) + '0', 1);
	return (len + 1);
}

int	ft_putlong_base(unsigned long nb, char *basestr, int basenum)
{
	int	len;

	len = 0;
	if (nb >= (unsigned long)basenum)
		len += ft_putlong_base(nb / basenum, basestr, basenum);
	ft_putchar(basestr[(nb % basenum)]);
	return (len + 1);
}

int	ft_write_ptr(void *ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (2 + ft_putlong_base((unsigned long)ptr, BASE16_LOW, 16));
}

int	ft_putnbr(int nb)
{
	int				len;

	len = 0;
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		len += 2;
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		len++;
	}
	if (ft_abs(nb) > 9)
		len += ft_putnbr(ft_abs(nb / 10));
	ft_putchar((ft_abs(nb % 10)) + '0');
	return (len + 1);
}