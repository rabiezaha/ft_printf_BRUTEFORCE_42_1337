/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:39:25 by razaha            #+#    #+#             */
/*   Updated: 2020/01/09 13:45:17 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	prconversion(char c)
{
	if (g_flags.minus && g_flags.zero)
	{
		g_flags.width = g_flags.zero;
		g_flags.zero = 0;
	}
	if (g_flags.minus)
	{
		ft_zero(g_flags.zero - 1);
		ft_putchar(c);
		ft_space(g_flags.width - 1);
	}
	else
	{
		ft_space(g_flags.width - 1);
		ft_zero(g_flags.zero - 1);
		ft_putchar(c);
	}
}
