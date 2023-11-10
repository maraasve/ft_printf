/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_specs_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:45:45 by marieke           #+#    #+#             */
/*   Updated: 2023/11/09 18:12:09 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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