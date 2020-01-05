/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:11:44 by razaha            #+#    #+#             */
/*   Updated: 2020/01/05 22:27:51 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_extractwidth(char *fmt)
{
	if (!ft_isconversion(*fmt))
	{
		g_nbrlen = 0;
		if (*fmt == '*')
		{
			flags.width = va_arg(g_args, int);
			g_nbrlen++;
		}
		else
		{
			flags.width = ft_atoi(fmt);
			ft_nbrlen(flags.width); 
		}
		if (flags.width < 0)
		{
			flags.minus = 1;
			flags.width *= -1;
		}
		if (*fmt == '0')
		{
			flags.zero = 1;
			g_nbrlen++;
		}
	}
}

void ft_extractpreci(char *fmt)
{
	if(*fmt == '.')
	{
		if (*(fmt + 1) == '*')
		{
			flags.prec = va_arg(g_args, int);
			g_nbrlen++;
		}
		else
		{
			flags.prec = ft_atoi(fmt + 1);
			ft_nbrlen(flags.prec);
		}
		g_nbrlen++;
	}
}

int	ft_checkflags(char *fmt)
{
	ft_extractwidth(fmt);
	ft_extractpreci(fmt + g_nbrlen);
	return (g_nbrlen);
}
