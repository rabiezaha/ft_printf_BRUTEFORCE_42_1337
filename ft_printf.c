/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 14:55:39 by razaha            #+#    #+#             */
/*   Updated: 2020/01/06 18:44:54 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkfmt(char *fmt)
{	
	while (*fmt)
	{
		if (*fmt == '%')
		{
			ft_resetstruct();
			fmt = ft_checkflags(fmt + 1);
			if (*(fmt) == '%')
				ft_putchar('%');
			if (*(fmt) == 's')
				strconversion(va_arg(g_args, char *));
			if (*(fmt) == 'd')
				nbrconversion(va_arg(g_args, int));
		}	
		else
			ft_putchar(*fmt);	
		fmt++;
	}
	//printf("\nminus->%d\nzero->%d\nwidth->%d\nprec->%d\n", flags.minus, flags.zero, flags.width,flags.prec);
}

int	ft_printf(const char *fmt, ...)
{
	g_ret = 0;
	va_start(g_args, fmt);
	ft_checkfmt((char *)fmt);
	va_end(g_args);
	return (g_ret);
}

