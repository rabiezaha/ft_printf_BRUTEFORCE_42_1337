/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 21:42:41 by razaha            #+#    #+#             */
/*   Updated: 2020/01/05 22:24:22 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_spaceleft(int i, int n)
{
	ft_putnbr(n);
	while(i-- )
		ft_putchar(' ');
}

void ft_spaceright(int i, int n)
{
	while(i-- )
		ft_putchar(' ');
	ft_putnbr(n);
}

void ft_zero(int i, int n)
{
	while(i-- )
		ft_putchar('0');
	ft_putnbr(n);
}
