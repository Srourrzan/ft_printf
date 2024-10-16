/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:04:28 by rsrour            #+#    #+#             */
/*   Updated: 2024/09/05 18:08:09 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"


void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			sign = 1;
			n++;
		}
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd(n % 10 + '0' + sign, fd);
}
/*
int	main(void)
{
	int	n;

	n = -576;
	ft_putnbr_fd(n, 1);
	return (0);
}
*/
