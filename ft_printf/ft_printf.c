/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:21:06 by slin              #+#    #+#             */
/*   Updated: 2021/12/03 21:24:35 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_percent(const char c, va_list args, int *i)
{
	if (c == 'c')
		*i = *i + ft_putchar_printf(args);
	else if (c == 's')
		*i = *i + ft_putstr_printf(args);
	else if (c == 'p')
		*i = *i + ft_putnbr_hexa_pointeur_printf(args);
	else if (c == 'd' || c == 'i')
		*i = *i + ft_putnbr_printf(args);
	else if (c == 'u')
		*i = *i + ft_putnbr_unsigned_printf(args);
	else if (c == 'x')
		*i = *i + ft_putnbr_hexa_printf(args);
	else if (c == 'X')
		*i = *i + ft_putnbr_hexa_up_printf(args);
	else
	{
		ft_putchar('%');
		*i = *i + 1;
	}
}

static int	ft_cond(const char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == '%' || c == 'X')
		return (1);
	return (0);
}

static int	ft_init(const char *fmt, va_list args, int compteur)
{
	unsigned int	i;

	i = 0;
	while (fmt[i] != '\0')
	{	
		if (fmt[i] == '%')
		{
			if (ft_cond(fmt[i + 1]))
			{
				ft_percent(fmt[i + 1], args, &compteur);
				i = i + 2;
			}
		}
		else
		{
			ft_putchar(fmt[i]);
			i++;
			compteur++;
		}
	}
	return (compteur);
}

int	ft_printf(const char *fmt, ...)
{
	va_list			args;
	int				compteur;

	compteur = 0;
	va_start(args, fmt);
	compteur = ft_init(fmt, args, compteur);
	va_end(args);
	return (compteur);
}
