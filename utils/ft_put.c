/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 01:27:06 by razaha            #+#    #+#             */
/*   Updated: 2020/01/09 01:27:09 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_ret++;
}

void	ft_putstr(char *s, int i)
{
	while (i-- && *s != '\0')
	{
		ft_putchar(*s);
		s++;
	}
}

void	ft_putnbr(long n)
{
	long inb;

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

void	ft_puthex(unsigned int n, int x)
{
	char *lx;
	char *ux;

	lx = "0123456789abcdef";
	ux = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_puthex(n / 16, x);
		ft_putchar(x == 0 ? lx[n % 16] : ux[n % 16]);
	}
	else
		ft_putchar(x == 0 ? lx[n % 16] : ux[n % 16]);
}

void	ft_puthex_p(unsigned long n, int x)
{
	char *lx;
	char *ux;

	lx = "0123456789abcdef";
	ux = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_puthex_p(n / 16, x);
		ft_putchar(x == 0 ? lx[n % 16] : ux[n % 16]);
	}
	else
		ft_putchar(x == 0 ? lx[n % 16] : ux[n % 16]);
}
