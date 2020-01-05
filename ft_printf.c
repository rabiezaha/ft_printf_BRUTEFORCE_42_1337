/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 14:55:39 by razaha            #+#    #+#             */
/*   Updated: 2020/01/05 22:14:57 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkfmt(char *fmt)
{	
	int		jump;

	jump = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			ft_resetstruct();
			jump =  ft_checkflags((char *)fmt + 1);
			if (*(fmt + jump + 1) == '%')
				ft_putchar('%');
			if (*(fmt + jump + 1) == 's')
				strconversion(va_arg(g_args, char *));
			if (*(fmt + jump + 1) == 'd')
				nbrconversion(va_arg(g_args, int));
			fmt += jump + 1;
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

