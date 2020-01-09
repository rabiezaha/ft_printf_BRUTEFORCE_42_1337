/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:44:07 by razaha            #+#    #+#             */
/*   Updated: 2020/01/09 13:45:17 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	xconversion2(unsigned int n, int n_len, int x)
{
	if (g_flags.minus)
	{
		ft_zero(g_flags.zero - n_len);
		ft_puthex(n, x);
		ft_space(g_flags.width - (g_flags.zero > n_len ? g_flags.zero : n_len));
	}
	else
	{
		ft_space(g_flags.width - (g_flags.zero > n_len ? g_flags.zero : n_len));
		ft_zero(g_flags.zero - n_len);
		ft_puthex(n, x);
	}
}

void	xconversion(unsigned int n, int x)
{
	int n_len;

	n_len = ft_hexlen(n);
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
	xconversion2(n, n_len, x);
}
