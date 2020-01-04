/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 14:55:39 by razaha            #+#    #+#             */
/*   Updated: 2020/01/04 23:17:09 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_checkfmt(char *fmt, va_list arg)
{	
	int		ret;
	int		jump;

	ret = 0;
	jump = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			jump =  ft_checkflags((char *)fmt + 1);
			if (*(fmt + jump + 1) == '%')
				ret += ft_putchar('%');
			if (*(fmt + jump + 1) == 's')
				ret += strconversion(va_arg(arg, char *));
			if (*(fmt + jump + 1) == 'd')
				ret += nbrconversion(va_arg(arg, int));
			fmt += jump + 1; 
		}	
		else
			ret += ft_putchar(*fmt);	
		fmt++;
	}
	return (ret);
}

int	ft_printf(const char *fmt, ...)
{
	int		ret;
	va_list arg;

	va_start(arg, fmt);
	ret = ft_checkfmt((char *)fmt, arg);
	va_end(arg);
	return (ret);
}
