/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 21:42:41 by razaha            #+#    #+#             */
/*   Updated: 2020/01/06 18:47:48 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_spaceleft(int i, int n)
{
	while(i-- > 0)
		ft_putchar(' ');
	
	if (flags.prec == -1)
		ft_putnbr(n > 0 ? n : -n);
}

void ft_spaceright(int i, int n)
{
	ft_putnbr(n > 0 ? n : -n);
	while(i-- > 0)
		ft_putchar(' ');
}

int ft_zero(int i, int n)
{
	int c;

	c = i;
	while(i-- > 0)
		ft_putchar('0');
	if (!flags.minus)
		ft_putnbr(n > 0 ? n : -n);
	return (c > 0 ? c : 0);

}
