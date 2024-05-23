/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyamli <zakariayamli00@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:03:06 by zyamli            #+#    #+#             */
/*   Updated: 2024/03/27 02:20:54 by zyamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, int *len, int fd)
{
	if (!str)
		return (0);
	while (*str)
	{
		write(fd, str, 1);
		str++;
		(*len)++;
	}
	return (1);
}
