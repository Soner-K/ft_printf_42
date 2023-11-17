/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:59:20 by sokaraku          #+#    #+#             */
/*   Updated: 2023/11/17 17:39:15 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include "libft/libft.h"
# include <stdarg.h>

void	to_hex(unsigned long nb, char c, char turn, int *size);
void	ft_putstr(char *str, int *size);
void	ft_putnbr_long(long nb, int	*size);

int		ft_printf(const char *str, ...);

#endif
