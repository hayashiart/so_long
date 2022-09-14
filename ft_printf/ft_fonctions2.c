/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:37:58 by slin              #+#    #+#             */
/*   Updated: 2021/12/03 21:34:42 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_printf(va_list args)
{
	int	nb;
	int	i;

	i = 0;
	nb = va_arg(args, int);
	ft_putnbr(nb, &i);
	return (i);
}

int	ft_putnbr_unsigned_printf(va_list args)
{
	unsigned int	nb;
	int				i;

	i = 0;
	nb = va_arg(args, unsigned int);
	ft_putnbr(nb, &i);
	return (i);
}

int	ft_putnbr_hexa_printf(va_list args)
{
	unsigned int	nb;
	int				i;

	i = 0;
	nb = va_arg(args, unsigned int);
	ft_putnbr_hexa(nb, &i);
	return (i);
}

int	ft_putnbr_hexa_up_printf(va_list args)
{
	unsigned int	nb;
	int				i;

	i = 0;
	nb = va_arg(args, unsigned int);
	ft_putnbr_hexa_up(nb, &i);
	return (i);
}
