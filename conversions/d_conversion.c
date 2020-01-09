/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:41:59 by razaha            #+#    #+#             */
/*   Updated: 2020/01/09 13:45:17 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	dconversion2(int n, int n_len)
{
	if (g_flags.minus)
	{
		if (n < 0 && n != -2147483648)
			ft_putchar('-');
		ft_zero(g_flags.zero - n_len);
		ft_putnbr(n < 0 ? -n : n);
		ft_space(g_flags.width - (g_flags.zero > n_len ? g_flags.zero : n_len));
	}
	else
	{
		ft_space(g_flags.width - (g_flags.zero > n_len ? g_flags.zero : n_len));
		if (n < 0 && n != -2147483648)
			ft_putchar('-');
		ft_zero(g_flags.zero - n_len);
		ft_putnbr(n < 0 ? -n : n);
	}
}

void	dconversion(int n)
{
	int n_len;

	n_len = ft_nbrlen(n);
	if (g_flags.prec > -1)
	{
		if (n < 0)
			g_flags.prec++;
		g_flags.width = (g_flags.zero ? g_flags.zero : g_flags.width);
		g_flags.zero = g_flags.prec;
		if (n == 0 && !g_flags.prec)
		{
			if (!g_flags.width)
				return ;
			ft_space(g_flags.width);
			return ;
		}
		if (g_flags.prec > g_flags.width)
		{
			if (g_flags.zero < 0)
				g_flags.minus = 1;
			g_flags.width = (g_flags.zero < 0 ? -g_flags.zero : g_flags.zero);
		}
	}
	dconversion2(n, n_len);
}
