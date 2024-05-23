/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyamli <zakariayamli00@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:44:47 by zyamli            #+#    #+#             */
/*   Updated: 2024/03/27 02:20:06 by zyamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_toascii(int nb, int *len, int fd)
{
	char	str[10];
	int		i;

	i = 0;
	while (nb > 0)
	{
		str[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	while (i--)
	{
		write(fd, &str[i], 1);
		(*len)++;
	}
}

void	ft_putnbr(int n, int *len, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		(*len) += 11;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		(*len)++;
		n = -n;
		ft_toascii(n, len, fd);
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		(*len)++;
	}
	else
		ft_toascii(n, len, fd);
}
