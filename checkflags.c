/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:11:44 by razaha            #+#    #+#             */
/*   Updated: 2020/01/06 18:44:31 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_extractwidth(char *fmt)
{
	if (!ft_isconversion(*fmt) && *fmt != '.')
	{
		if (*fmt == '-' && (flags.minus = 1))
			return (ft_extractwidth(fmt + 1));
		if (*fmt == '0' && (flags.zero = 1))
			return (ft_extractwidth(fmt + 1));
		if (*fmt == '*')
		{
			flags.width = va_arg(g_args, int);
			fmt += ft_nbrlen(flags.width);
		}
		else
		{
			flags.width = ft_atoi(fmt);
			fmt += ft_nbrlen(flags.width);
		}
		if (flags.width < 0)
		{
			flags.minus = 1;
			flags.width *= -1;
		}
	}
	return (fmt);
}

char *ft_extractpreci(char *fmt)
{
	if(*fmt == '.')
	{
		if (*(fmt + 1) == '*')
		{
			flags.prec = va_arg(g_args, int);
			fmt++;
		}
		else
		{
			flags.prec = ft_atoi(fmt + 1);
			fmt += ft_nbrlen(flags.prec);
		}
		flags.zero = 0;
		fmt++;
	}
	return (fmt);
}

char	*ft_checkflags(char *fmt)
{
	return (ft_extractpreci(ft_extractwidth(fmt)));
}
