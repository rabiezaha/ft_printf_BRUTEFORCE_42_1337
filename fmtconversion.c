/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmtconversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 12:37:35 by razaha            #+#    #+#             */
/*   Updated: 2020/01/07 15:59:54 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	strconversion(char *s)
{
	ft_putstr(s);
}

void	nbrconversion2(int n, int n_len)
{
	if (flags.minus)
	{
		if (n < 0)
			ft_putchar('-');
		ft_zero(flags.zero - n_len);
		ft_putnbr(n < 0 ? -n : n);
		ft_space(flags.width - (flags.zero > n_len ? flags.zero : n_len));
	}
	else
	{
		ft_space(flags.width - (flags.zero > n_len ? flags.zero : n_len));
		if (n < 0)
			ft_putchar('-');
		ft_zero(flags.zero - n_len);
		ft_putnbr(n < 0 ? -n : n);
	}
}

void	nbrconversion(int n)
{
	int n_len;

	n_len = ft_nbrlen(n);
	if (flags.prec > -1)
	{
		if (n < 0)
			flags.prec++;
		if (n == 0 && !flags.prec)
		{
			if (!flags.width)
				return ;
			ft_space(flags.width);
			return ;
		}
		if (flags.prec > flags.width)
			flags.width = flags.zero;
		flags.zero = flags.prec;
	}
	nbrconversion2(n , n_len);
}
