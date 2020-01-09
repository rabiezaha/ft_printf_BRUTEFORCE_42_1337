/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:40:55 by razaha            #+#    #+#             */
/*   Updated: 2020/01/09 00:41:14 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	sconversion(char *s)
{
	if (s == NULL)
		s = "(null)";
	if (flags.minus)
	{
		ft_putstr(s, flags.prec);
		ft_space(flags.width - ((flags.prec > ft_strlen(s)
		|| flags.prec == -1) ? ft_strlen(s) : flags.prec));
	}
	else
	{
		ft_space(flags.width - ((flags.prec > ft_strlen(s)
		|| flags.prec == -1) ? ft_strlen(s) : flags.prec));
		ft_putstr(s, flags.prec);
	}
}
