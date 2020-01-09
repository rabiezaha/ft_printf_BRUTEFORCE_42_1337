/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:46:30 by razaha            #+#    #+#             */
/*   Updated: 2020/01/09 14:25:40 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	pconversion2(unsigned long n, int n_len)
{
	if (g_flags.minus)
	{
		ft_putstr("0x", 2);
		ft_zero(g_flags.zero - n_len + 2);
		ft_puthex_p(n, 0);
		ft_space(g_flags.width - (g_flags.zero > n_len ? g_flags.zero : n_len));
	}
	else
	{
		ft_space(g_flags.width - (g_flags.zero > n_len ? g_flags.zero : n_len));
		ft_putstr("0x", 2);
		ft_zero(g_flags.zero - n_len + 2);
		ft_puthex_p(n, 0);
	}
}

void	pconversion(unsigned long n)
{
	int n_len;

	n_len = ft_hexlen_p(n);
	if (g_flags.prec > -1)
	{
		if (n == 0 && !g_flags.prec)
		{
			if (!g_flags.width || g_flags.minus)
				ft_putstr("0x", 2);
			if (g_flags.width)
				ft_space(g_flags.width - 2);
			if (g_flags.width && !g_flags.minus)
				ft_putstr("0x", 2);
			return ;
		}
		if (g_flags.prec > g_flags.width)
		{
			if (g_flags.zero < 0)
				g_flags.minus = 1;
			g_flags.width = (g_flags.zero < 0 ? -g_flags.zero : g_flags.zero);
		}
		g_flags.zero = g_flags.prec;
	}
	pconversion2(n, n_len + 2);
}
