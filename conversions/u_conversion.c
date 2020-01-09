/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:45:15 by razaha            #+#    #+#             */
/*   Updated: 2020/01/09 13:45:17 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	uconversion2(unsigned int n, int n_len)
{
	if (g_flags.minus)
	{
		ft_zero(g_flags.zero - n_len);
		ft_putnbr(n);
		ft_space(g_flags.width - (g_flags.zero > n_len ? g_flags.zero : n_len));
	}
	else
	{
		ft_space(g_flags.width - (g_flags.zero > n_len ? g_flags.zero : n_len));
		ft_zero(g_flags.zero - n_len);
		ft_putnbr(n);
	}
}

void	uconversion(unsigned int n)
{
	int n_len;

	n_len = ft_nbrlen(n);
	if (g_flags.prec > -1)
	{
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
	uconversion2(n, n_len);
}
