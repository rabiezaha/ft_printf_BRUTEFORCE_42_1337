/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:00:35 by razaha            #+#    #+#             */
/*   Updated: 2020/01/05 20:44:40 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1 , &c, 1);
	g_ret++;
}

void	ft_putstr(char *s)
{

	while(*s != '\0')
	{
		ft_putchar(*s);
		s++;
	}
}

void	ft_putnbr(int n)
{
	unsigned int inb;

	if (n < 0)
	{
		ft_putchar('-');
		inb = n * -1;
	}
	else
		inb = n;
	if (inb > 9)
		ft_putnbr(inb / 10);
	ft_putchar(inb % 10 + '0');
}
