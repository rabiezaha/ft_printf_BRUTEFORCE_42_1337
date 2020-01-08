/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 14:55:39 by razaha            #+#    #+#             */
/*   Updated: 2020/01/08 16:06:52 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkfmt(char *fmt)
{	
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			ft_resetstruct();
			fmt = ft_checkflags(fmt + 1);
			if (*(fmt) == '%')
				prconversion('%');
			if (*(fmt) == 'c')
				cconversion(va_arg(g_args, int));
			if (*(fmt) == 's')
				sconversion(va_arg(g_args, char *));
			if (*(fmt) == 'p')
				pconversion(va_arg(g_args, unsigned long));
			if (*(fmt) == 'd' || *(fmt) == 'i')
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

