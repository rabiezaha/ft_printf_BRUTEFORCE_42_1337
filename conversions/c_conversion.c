/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:41:25 by razaha            #+#    #+#             */
/*   Updated: 2020/01/09 13:45:17 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	cconversion(char c)
{
	if (g_flags.minus)
	{
		ft_putchar(c);
		ft_space(g_flags.width - 1);
	}
	else
	{
		ft_space(g_flags.width - 1);
		ft_putchar(c);
	}
}
