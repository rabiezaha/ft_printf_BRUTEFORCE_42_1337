/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:39:25 by razaha            #+#    #+#             */
/*   Updated: 2020/01/09 00:40:23 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	prconversion(char c)
{
	if (flags.minus && flags.zero)
	{
		flags.width = flags.zero;
		flags.zero = 0;
	}
	if (flags.minus)
	{
		ft_zero(flags.zero - 1);
		ft_putchar(c);
		ft_space(flags.width - 1);
	}
	else
	{
		ft_space(flags.width - 1);
		ft_zero(flags.zero - 1);
		ft_putchar(c);
	}
}
