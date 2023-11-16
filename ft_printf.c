/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:07:37 by sokaraku          #+#    #+#             */
/*   Updated: 2023/11/16 19:39:01 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_putnbr_long(long nb, int	*size)
{
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', 1);
		(*size)++;
	}
	if (nb / 10)
	{
		(*size)++;
		ft_putnbr_long(nb / 10, size);
	}
	else
		(*size)++;
	ft_putchar_fd((nb % 10) + '0', 1);
}

static void	ft_putstr(char *str, int *size)
{
	(*size) += ft_strlen(str);
	while (*str)
		ft_putchar_fd(*str++, 1);
}

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
		to_hex(va_arg(arg, size_t), c, 0, size);
	if (c == 'p')
		to_hex(va_arg(arg, size_t), c, 1, size);
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		(*size)++;
	}
	if (c == 'u')
		ft_putnbr_long((unsigned int) va_arg(arg, unsigned int), size);
	(*str) += 2;
}

int ft_printf(const char *str, ...)
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

int	main()
{
	void	*tmp;
	int		a;

	a = 5;
	tmp = &a;
	ft_printf("FT_PRINTF\n%c\n%s\n%p\n%u\n%x\n%X\n%%\n%d\n%i\n", 'a', "salut", tmp, -1, 42, 42, 2147483648, 45);
	printf("PRINTF\n%c\n%s\n%p\n%u\n%x\n%X\n%%\n%d\n%i\n", 'a', "salut", tmp, -1, 42, 42, 2147483647, 45);

	a = ft_printf("salut %s\n %d\n %X\n", "salut", -4545, 42);
	printf("a = de ft_printf = %d\n", a);

	a = printf("salut %s\n %d\n %X\n", "salut", -4545, 42);
	printf("a = de printf = %d\n", a);

}

