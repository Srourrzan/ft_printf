/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:23:17 by rsrour            #+#    #+#             */
/*   Updated: 2024/10/26 20:23:20 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"
#include "header/libft.h"

int	ft_printf(const char *fmt, ...)
{
	int				i;
	int				num_char;
	va_list			args;
	int				x;
	//char			x;
	char			*str;
	unsigned long	ptr_add;
	unsigned int	x_value;
	unsigned int	u_value;

	i = 0;
	va_start(args, fmt);
	num_char = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			num_char -= 1;
			if (fmt[i] == 'i' || fmt[i] == 'd')
			{
				x = va_arg(args, int);
				num_char += ft_putnbr_fd(x, 1, 0) + 1;
				num_char -= 1;
			}
			else if (fmt[i] == '%')
			{
				ft_putchar_fd('%', 1);
			}
			else if (fmt[i] == 'c')
			{
				x = va_arg(args, int);
				ft_putchar_fd(x, 1);
			}
			else if (fmt[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
				{
					num_char += 5;
					ft_putstr_fd("(null)", 1);
				}
				else
				{
					while (*str)
					{
						ft_putchar_fd(*str++, 1);
						num_char += 1;
					}
					num_char -= 1;
				}
			}
			else if (fmt[i] == 'p')
			{
				ptr_add = va_arg(args, unsigned long);
				if (ptr_add == 0)
				{
					num_char += 4;
					ft_putstr_fd("(nil)", 1);
				}
				else
				{
					ft_putchar_fd('0', 1);
					ft_putchar_fd('x', 1);
					num_char += ft_convert_decimel_to_hexa_p(ptr_add);
					num_char += 2;
					num_char -= 1;
				}
			}
			else if (fmt[i] == 'x' || fmt[i] == 'X')
			{
				x_value = va_arg(args, unsigned int);
				num_char += ft_convert_decimel_to_hexa_x(x_value, fmt[i]);
				num_char -= 1;
			}
			else if (fmt[i] == 'u')
			{
				u_value = va_arg(args, unsigned int);
				num_char += ft_convert_signed_to_unsigned(u_value);
				num_char -= 1;
			}
		}
		else
		{
			ft_putchar_fd(fmt[i], 1);
		}
		i++;
		va_end(args);
	}
	return (i + num_char);
}
