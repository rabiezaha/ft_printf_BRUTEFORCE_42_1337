/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:40:55 by razaha            #+#    #+#             */
/*   Updated: 2020/01/09 13:45:17 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	sconversion(char *s)
{
	if (s == NULL)
		s = "(null)";
	if (g_flags.minus)
	{
		ft_putstr(s, g_flags.prec);
		ft_space(g_flags.width - ((g_flags.prec > ft_strlen(s)
		|| g_flags.prec == -1) ? ft_strlen(s) : g_flags.prec));
	}
	else
	{
		ft_space(g_flags.width - ((g_flags.prec > ft_strlen(s)
		|| g_flags.prec == -1) ? ft_strlen(s) : g_flags.prec));
		ft_putstr(s, g_flags.prec);
	}
}
