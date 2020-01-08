/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:00:35 by razaha            #+#    #+#             */
/*   Updated: 2020/01/08 14:38:44 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putchar(char c)
{
	write(1 , &c, 1);
	g_ret++;
}

void	ft_putstr(char *s , int i)
{
	while(i-- &&*s != '\0')
	{
		ft_putchar(*s);
		s++;
	}
}

int	ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (*s++)
		len++;
	return (len);
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

void ft_puthex(unsigned int n, int x)
{
	char *hex;
	char *HEX;

	hex = "0123456789abcdef";
	HEX = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_puthex(n/16, x);
		ft_putchar(x == 0 ? hex[n%16] : HEX[n%16]);
	}
	else
		ft_putchar(x == 0 ? hex[n%16] : HEX[n%16]);
}

void ft_puthex_p(unsigned long n, int x)
{
	char *hex;
	char *HEX;

	hex = "0123456789abcdef";
	HEX = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_puthex_p(n/16, x);
		ft_putchar(x == 0 ? hex[n%16] : HEX[n%16]);
	}
	else
		ft_putchar(x == 0 ? hex[n%16] : HEX[n%16]);
}

