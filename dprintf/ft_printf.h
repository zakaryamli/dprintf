/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyamli <zakariayamli00@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:46:53 by zyamli            #+#    #+#             */
/*   Updated: 2024/03/27 02:17:54 by zyamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(int fd, const char *str, ...);
void	ft_putchar(int c, int *len, int fd);
void	ft_puthex(unsigned int a, char c, int *len, int fd);
void	ft_putnbr(int n, int *len, int fd);
void	ft_putptr(void *i, int *len, int fd);
int		ft_putstr(char *str, int *len, int fd);
void	ft_putunsigned(unsigned int n, int *len, int fd);
#endif