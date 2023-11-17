/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:07:37 by sokaraku          #+#    #+#             */
/*   Updated: 2023/11/17 17:39:25 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_and_print(const char **str, char c, va_list arg, int *size)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(arg, int), 1);
		(*size)++;
	}
	if (c == 's')
		ft_putstr(va_arg(arg, char *), size);
	if (c == 'i' || c == 'd')
		ft_putnbr_long((int) va_arg(arg, int), size);
	if (c == 'x' || c == 'X')
		to_hex(va_arg(arg, unsigned int), c, 0, size);
	if (c == 'p')
		to_hex(va_arg(arg, unsigned long), c, 1, size);
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		(*size)++;
	}
	if (c == 'u')
		ft_putnbr_long((unsigned int) va_arg(arg, unsigned int), size);
	(*str) += 2;
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		size;

	va_start(arg, str);
	size = 0;
	while (*str)
	{
		if (*str == '%')
			ft_check_and_print(&str, *(str + 1), arg, &size);
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			size++;
		}
	}
	va_end(arg);
	return (size);
}
