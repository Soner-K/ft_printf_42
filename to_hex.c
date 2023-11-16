/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:12:23 by sokaraku          #+#    #+#             */
/*   Updated: 2023/11/16 19:37:43 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	to_hex(size_t nb, char c, char turn, int *size)
{
	char	*base;

	if (c == 'X')
		base = ft_strdup("0123456789ABCDEF");
	else
		base = ft_strdup("0123456789abcdef");
	if (turn == 1)
		ft_putstr_fd("0x", 1);
	if (nb / 16)
	{
		(*size)++;
		to_hex(nb / 16, c, 0, size);
	}
	else
		(*size)++;
	ft_putchar_fd(base[nb % 16], 1);
}
