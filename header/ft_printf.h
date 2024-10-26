/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:22:28 by rsrour            #+#    #+#             */
/*   Updated: 2024/10/26 20:22:31 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *fmt, ...);
int	ft_convert_decimel_to_hexa_p(unsigned long number);
int	ft_convert_decimel_to_hexa_x(unsigned int number, char type);
int	ft_convert_signed_to_unsigned(unsigned int number);

#endif
