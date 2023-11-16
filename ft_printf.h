/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:59:20 by sokaraku          #+#    #+#             */
/*   Updated: 2023/11/16 19:27:52 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include "../libft/libft.h"
# include <stdarg.h>

void	to_hex(size_t nb, char c, char turn, int *size);

int		ft_printf(const char *str, ...);

#endif
