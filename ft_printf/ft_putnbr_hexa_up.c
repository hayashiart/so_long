/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:31:03 by slin              #+#    #+#             */
/*   Updated: 2021/12/03 21:59:23 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexa_up(unsigned long nb, int *i)
{
	if (nb >= 16)
	{
		ft_putnbr_hexa_up(nb / 16, i);
		ft_putnbr_hexa_up(nb % 16, i);
	}
	if (nb < 10 && nb >= 0)
	{
		ft_putchar(nb + '0');
		*i = *i + 1;
	}	
	else if (nb >= 10 && nb < 16)
	{
		ft_putchar (nb + 'A' - 10);
		*i = *i + 1;
	}
	else
		return ;
}
