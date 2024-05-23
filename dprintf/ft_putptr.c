/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyamli <zakariayamli00@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:59:10 by zyamli            #+#    #+#             */
/*   Updated: 2024/03/27 02:20:34 by zyamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthexptr(unsigned long long a, int *len, int fd)
{
	if (a >= 16)
		ft_puthexptr(a / 16, len, fd);
	ft_putchar("0123456789abcdef"[a % 16], len, fd);
}

void	ft_putptr(void *i, int *len, int fd)
{
	write(fd, "0x", 2);
	(*len) += 2;
	ft_puthexptr((unsigned long long)i, len, fd);
}
