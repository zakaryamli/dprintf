/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyamli <zakariayamli00@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:45:23 by zyamli            #+#    #+#             */
/*   Updated: 2024/03/27 02:18:55 by zyamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int a, char c, int *len, int fd)
{
	if (c == 'x')
	{
		if (a >= 16)
			ft_puthex(a / 16, c, len, fd);
		ft_putchar("0123456789abcdef"[a % 16], len, fd);
	}
	else if (c == 'X')
	{
		if (a >= 16)
			ft_puthex(a / 16, c, len, fd);
		ft_putchar("0123456789ABCDEF"[a % 16], len, fd);
	}
}
