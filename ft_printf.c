/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 14:55:39 by razaha            #+#    #+#             */
/*   Updated: 2020/01/08 01:07:54 by razaha           ###   ########.fr       */
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
				charconversion('%');
			if (*(fmt) == 's')
				strconversion(va_arg(g_args, char *));
			if (*(fmt) == 'c')
				charconversion(va_arg(g_args, int));
			if (*(fmt) == 'd')
				dconversion(va_arg(g_args, int));
			if (*(fmt) == 'u')
				uconversion(va_arg(g_args,unsigned int));
			if (*(fmt) == 'x' || *(fmt) == 'X')
				xconversion(va_arg(g_args,unsigned int), (*(fmt) == 'x' ? 0 : 1));
		}	
		else
			ft_putchar(*fmt);	
		fmt++;
	}
//	printf("\nminus->%d\nzero->%d\nwidth->%d\nprec->%d\n", flags.minus, flags.zero, flags.width,flags.prec);
}

int	ft_printf(const char *fmt, ...)
{
	g_ret = 0;
	va_start(g_args, fmt);
	ft_checkfmt((char *)fmt);
	va_end(g_args);
	return (g_ret);
}

