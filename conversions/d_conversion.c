/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:41:59 by razaha            #+#    #+#             */
/*   Updated: 2020/01/09 00:43:40 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	dconversion2(int n, int n_len)
{
	if (flags.minus)
	{
		if (n < 0 && n != -2147483648)
			ft_putchar('-');
		ft_zero(flags.zero - n_len);
		ft_putnbr(n < 0 ? -n : n);
		ft_space(flags.width - (flags.zero > n_len ? flags.zero : n_len));
	}
	else
	{
		ft_space(flags.width - (flags.zero > n_len ? flags.zero : n_len));
		if (n < 0 && n != -2147483648)
			ft_putchar('-');
		ft_zero(flags.zero - n_len);
		ft_putnbr(n < 0 ? -n : n);
	}
}

void	dconversion(int n)
{
	int n_len;

	n_len = ft_nbrlen(n);
	if (flags.prec > -1)
	{
		if (n < 0)
			flags.prec++;
		flags.width = (flags.zero ? flags.zero : flags.width);
		flags.zero = flags.prec;
		if (n == 0 && !flags.prec)
		{
			if (!flags.width)
				return ;
			ft_space(flags.width);
			return ;
		}
		if (flags.prec > flags.width)
		{
			if (flags.zero < 0)
				flags.minus = 1;
			flags.width = (flags.zero < 0 ? -flags.zero : flags.zero);
		}
	}
	dconversion2(n, n_len);
}
