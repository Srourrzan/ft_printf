/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitpod <gitpod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:39:29 by gitpod            #+#    #+#             */
/*   Updated: 2024/10/27 18:51:58 by gitpod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"
#include "header/libft.h"

int	print_signed_numbers(int number, int num_char)
{
	num_char += ft_putnbr_fd(number, 1, 0) + 1;
	return (num_char - 1);
}

int	print_str(char *str, int num_char)
{
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
	return (num_char);
}

int	print_ptr(unsigned long ptr_add, int num_char)
{
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
	return (num_char);
}

int	print_hexa(unsigned int x_value, int num_char, char type)
{
	num_char += ft_convert_decimel_to_hexa_x(x_value, type);
	return (num_char - 1);
}

int	print_unsigned(unsigned int u_value, int num_char)
{
	num_char += ft_convert_signed_to_unsigned(u_value);
	return (num_char - 1);
}
