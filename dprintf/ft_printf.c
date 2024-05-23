/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyamli <zakariayamli00@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:52:41 by zyamli            #+#    #+#             */
/*   Updated: 2024/05/23 11:56:40 by zyamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_checkf(const char *s, va_list ap, int *len, int fd)
{
	if (*s == 'c')
		ft_putchar(va_arg(ap, int), len, fd);
	else if (*s == 's')
	{
		if (!ft_putstr(va_arg(ap, char *), len, fd))
			ft_putstr("(null)", len, fd);
	}
	else if (*s == 'i' || *s == 'd')
		ft_putnbr(va_arg(ap, int), len, fd);
	else if (*s == 'u')
		ft_putunsigned(va_arg(ap, unsigned int), len, fd);
	else if (*s == 'x' || *s == 'X')
		ft_puthex(va_arg(ap, int), *s, len, fd);
	else if (*s == 'p')
		ft_putptr(va_arg(ap, void *), len, fd);
	else if (*s == '%')
	{
		write(fd, "%", 1);
		(*len)++;
	}
	else
	{
		write(fd, s, 1);
		(*len)++;
	}
}

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list	ap;
	int		len;

	if (write(fd, "", 0) == -1)
		return (-1);
	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!*str)
				break ;
			ft_checkf(str, ap, &len, fd);
		}
		else
		{
			write(fd, str, 1);
			len++;
		}
		str++;
	}
	va_end(ap);
	return (len);
}

