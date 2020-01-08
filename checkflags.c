/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:11:44 by razaha            #+#    #+#             */
/*   Updated: 2020/01/08 23:43:59 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *skip_zero(char *fmt)
{
	flags.zero = ft_atoi(fmt);
	while (*fmt >= '0' && *fmt <= '9')
		fmt++;
	if (*fmt == '*')
		flags.zero = 1;
	return (fmt - 1);
}

char	*ft_extractwidth(char *fmt)
{
	if (!ft_isconversion(*fmt) && *fmt != '.')
	{
		if ((*fmt == '-' && (flags.minus = 1)) ||
			(*fmt == '0' && (fmt = skip_zero(fmt))))
			return (ft_extractwidth(fmt + 1));
		if (*fmt == '*')
		{
			flags.zero ? (flags.zero = va_arg(g_args, int))
			: (flags.width = va_arg(g_args, int));
			fmt++;
		}
		else
		{
			flags.zero ? (flags.zero = ft_atoi(fmt))
			: (flags.width = ft_atoi(fmt));
			fmt += ft_nbrlen(flags.zero ? flags.zero : flags.width);
		}
		if (flags.width < 0 && (flags.minus = 1))
			flags.width *= -1;
		if (flags.zero < 0 && (flags.minus = 1)
		&& (flags.width = (flags.zero * -1)))
			flags.zero = 0;
	}
//  printf("minus:%d\nzero:%d\nwidth:%d\nprec:%d\n", flags.minus,flags.zero,flags.width,flags.prec);

	return (fmt);
}

char	*ft_extractpreci(char *fmt)
{
	if (!ft_isconversion(*fmt) && *fmt == '.')
	{
		if (*(fmt + 1) == '*')
		{
			flags.prec = va_arg(g_args, int);
			if (flags.prec < 0)
				flags.prec = -1;
			fmt++;
		}
		else
		{
			while (*(fmt + 1) == '0')
				fmt++; 
			flags.prec = ft_atoi(fmt + 1);
			if (*(fmt + 1) >= '0' && *(fmt + 1) <= '9')
				fmt += ft_nbrlen(flags.prec);
		}
		fmt++;
	}
	return (fmt);
}

char	*ft_checkflags(char *fmt)
{
	return (ft_extractpreci(ft_extractwidth(fmt)));
}