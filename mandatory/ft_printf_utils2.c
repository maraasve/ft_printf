/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:06:22 by maraasve          #+#    #+#             */
/*   Updated: 2023/11/30 13:49:29 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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
