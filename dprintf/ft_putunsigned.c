/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyamli <zakariayamli00@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:57:11 by zyamli            #+#    #+#             */
/*   Updated: 2024/03/27 02:21:26 by zyamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_toascii(unsigned int nb, int *len, int fd)
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

void	ft_putunsigned(unsigned int n, int *len, int fd)
{
	if (n == 0)
	{
		write (fd, "0", 1);
		(*len)++;
	}
	else
		ft_toascii(n, len, fd);
}
