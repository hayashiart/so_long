/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:33:23 by slin              #+#    #+#             */
/*   Updated: 2021/11/30 19:18:18 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexa(unsigned long nb, int *i)
{
	if (nb >= 16)
	{
		ft_putnbr_hexa(nb / 16, i);
		ft_putnbr_hexa(nb % 16, i);
	}
	if (nb < 10 && nb >= 0)
	{
		ft_putchar(nb + '0');
		*i = *i + 1;
	}	
	else if (nb >= 10 && nb < 16)
	{
		ft_putchar (nb + 'a' - 10);
		*i = *i + 1;
	}
	else
		return ;
}
