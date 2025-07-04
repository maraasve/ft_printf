/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:22:48 by maraasve          #+#    #+#             */
/*   Updated: 2025/07/04 21:53:19 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

int	convert_specifiers(const char *str, va_list *args)
{
	int	i;

	i = 0;
	if (str[i + 1] == '%')
		return (ft_putchar('%'));
	if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if ((str[i + 1] == 's'))
		return (ft_putstr(va_arg(*args, char *)));
	if ((str[i + 1] == 'i' || str[i + 1] == 'd'))
		return (ft_putnbr(va_arg(*args, int)));
	if ((str[i + 1] == 'u'))
		return (ft_putuint(va_arg(*args, unsigned int)));
	if (str[i + 1] == 'x')
		return (ft_putlong_base(va_arg(*args, unsigned int), BASE16_LOW, 16));
	if (str[i + 1] == 'X')
		return (ft_putlong_base(va_arg(*args, unsigned int), BASE16_UP, 16));
	if (str[i + 1] == 'p')
		return (ft_write_ptr(va_arg(*args, void *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		start;
	int		len;
	va_list	args;

	va_start(args, str);
	i = 0;
	len = 0;
	start = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1])
		{
			len += ft_putpartstr(&str[start], (i - start));
			len += convert_specifiers(&str[i], &args);
			i += 2;
			start = i;
		}
		else
			i++;
	}
	len += ft_putpartstr(&str[start], (i - start));
	va_end(args);
	return (len);
}
