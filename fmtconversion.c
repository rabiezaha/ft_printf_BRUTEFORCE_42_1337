/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmtconversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 12:37:35 by razaha            #+#    #+#             */
/*   Updated: 2020/01/05 22:24:18 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	strconversion(char *s)
{
	ft_putstr(s);
}

void	nbrconversion(int n)
{
	g_nbrlen = 0;

	ft_nbrlen(n);
	if (flags.width <= g_nbrlen)
		ft_putnbr(n);
	else 
	{
		if (flags.zero)
			ft_zero(flags.width - g_nbrlen, n);
		else
			ft_spaceleft(flags.width - g_nbrlen, n );
	}
}
