/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:22:48 by maraasve          #+#    #+#             */
/*   Updated: 2023/11/30 13:53:36 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	convert_specifiers(const char *string, va_list args)
{
	int	i;

	i = 0;
	if (string[i + 1] == '%')
		return (ft_putchar('%'));
	if (string[i + 1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	if ((string[i + 1] == 's'))
		return (ft_putstr(va_arg(args, char *)));
	if ((string[i + 1] == 'i' || string[i + 1] == 'd'))
		return (ft_putnbr(va_arg(args, int)));
	if ((string[i + 1] == 'u'))
		return (ft_putuint(va_arg(args, unsigned int)));
	if (string[i + 1] == 'x')
		return (ft_putlong_base(va_arg(args, unsigned int), BASE16_LOW, 16));
	if (string[i + 1] == 'X')
		return (ft_putlong_base(va_arg(args, unsigned int), BASE16_UP, 16));
	if (string[i + 1] == 'p')
		return (ft_write_ptr(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *string, ...)
{
	int		i;
	int		start;
	int		len;
	va_list	args;

	va_start(args, string);
	i = 0;
	len = 0;
	start = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			len += ft_putpartstr(&string[start], (i - start));
			len += convert_specifiers(&string[i], args);
			i += 2;
			start = i;
		}
		else
			i++;
	}
	len += ft_putpartstr(&string[start], (i - start));
	return (len);
}
