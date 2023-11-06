/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:46:01 by maraasve          #+#    #+#             */
/*   Updated: 2023/11/06 17:49:49 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags_to_zero(t_flags *tabs)
{
	tabs->width = 0;
	tabs->precision = 0;
	tabs->zero_pad = 0;
	tabs->point = 0;
	tabs->sign = 0;
	tabs->dash = 0;
	tabs->space = 0;
	tabs->hash = 0;
	tabs->total_len = 0;
}
