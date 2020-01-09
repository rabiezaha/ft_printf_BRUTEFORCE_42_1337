/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:11:44 by razaha            #+#    #+#             */
/*   Updated: 2020/01/09 13:49:55 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_extractwidth(char *fmt)
{
	if (!ft_isconversion(*fmt) && *fmt != '.')
	{
		if ((*fmt == '-' && (g_flags.minus = 1)) ||
			(*fmt == '0' && (fmt = skip_zero(fmt))))
			return (ft_extractwidth(fmt + 1));
		if (*fmt == '*')
		{
			g_flags.zero ? (g_flags.zero = va_arg(g_args, int))
			: (g_flags.width = va_arg(g_args, int));
			fmt++;
		}
		else
		{
			g_flags.zero ? (g_flags.zero = ft_atoi(fmt))
			: (g_flags.width = ft_atoi(fmt));
			fmt += ft_nbrlen(g_flags.zero ? g_flags.zero : g_flags.width);
		}
		if (g_flags.width < 0 && (g_flags.minus = 1))
			g_flags.width *= -1;
		if (g_flags.zero < 0 && (g_flags.minus = 1)
		&& (g_flags.width = (g_flags.zero * -1)))
			g_flags.zero = 0;
	}
	return (fmt);
}

char	*ft_extractpreci(char *fmt)
{
	if (!ft_isconversion(*fmt) && *fmt == '.')
	{
		if (*(fmt + 1) == '*')
		{
			g_flags.prec = va_arg(g_args, int);
			if (g_flags.prec < 0)
				g_flags.prec = -1;
			fmt++;
		}
		else
		{
			while (*(fmt + 1) == '0')
				fmt++;
			g_flags.prec = ft_atoi(fmt + 1);
			if (*(fmt + 1) >= '0' && *(fmt + 1) <= '9')
				fmt += ft_nbrlen(g_flags.prec);
		}
		fmt++;
	}
	return (fmt);
}

char	*ft_checkflags(char *fmt)
{
	return (ft_extractpreci(ft_extractwidth(fmt)));
}
