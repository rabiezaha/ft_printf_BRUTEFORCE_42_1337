/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 14:55:39 by razaha            #+#    #+#             */
/*   Updated: 2020/01/09 00:34:34 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_checkfmt(char *fmt)
{
	ft_resetstruct();
	fmt = ft_checkflags(fmt + 1);
	if (*(fmt) == '%')
		prconversion('%');
	else if (*(fmt) == 'c')
		cconversion(va_arg(g_args, int));
	else if (*(fmt) == 's')
		sconversion(va_arg(g_args, char *));
	else if (*(fmt) == 'p')
		pconversion(va_arg(g_args, unsigned long));
	else if (*(fmt) == 'd' || *(fmt) == 'i')
		dconversion(va_arg(g_args, int));
	else if (*(fmt) == 'u')
		uconversion(va_arg(g_args, unsigned int));
	else if (*(fmt) == 'x' || *(fmt) == 'X')
		xconversion(va_arg(g_args, unsigned int), (*(fmt) == 'x' ? 0 : 1));
	else
		return (fmt - 1);
	return (fmt);
}

int		ft_printf(const char *fmt, ...)
{
	g_ret = 0;
	va_start(g_args, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
			fmt = ft_checkfmt((char *)fmt);
		else
			ft_putchar(*fmt);
		fmt++;
	}
	va_end(g_args);
	return (g_ret);
}
