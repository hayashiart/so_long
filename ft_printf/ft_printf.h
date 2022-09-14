/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:26:54 by slin              #+#    #+#             */
/*   Updated: 2021/12/03 21:37:11 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# ifdef __APPLE__
#  define MACRO "0x0"
# else
#  define MACRO "(nil)"
# endif
# include <stdarg.h>
# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

void	ft_putchar(char c);
void	ft_putnbr(long nb, int *i);
void	ft_putnbr_hexa(unsigned long nb, int *i);
void	ft_putnbr_hexa_up(unsigned long nb, int *i);
void	ft_putstr(char *str);
int		ft_putstr_printf(va_list args);
int		ft_putchar_printf(va_list args);
int		ft_putnbr_hexa_pointeur_printf(va_list args);
int		ft_putnbr_printf(va_list args);
int		ft_putnbr_unsigned_printf(va_list args);
int		ft_putnbr_hexa_printf(va_list args);
int		ft_putnbr_hexa_up_printf(va_list args);
int		ft_printf(const char *fmt, ...);
#endif
