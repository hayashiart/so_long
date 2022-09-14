/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:36:40 by slin              #+#    #+#             */
/*   Updated: 2021/12/02 18:21:36 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_printf(va_list args)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_putchar_printf(va_list args)
{
	int	c;

	c = va_arg(args, int);
	ft_putchar(c);
	return (1);
}

int	ft_putnbr_hexa_pointeur_printf(va_list args)
{
	unsigned long	nb;
	int				i;

	nb = va_arg(args, unsigned long);
	if (!nb)
	{
		ft_putstr(MACRO);
		i = 0;
		while (MACRO[i])
			i++;
		return (i);
	}
	ft_putstr("0x");
	i = 2;
	ft_putnbr_hexa(nb, &i);
	return (i);
}
