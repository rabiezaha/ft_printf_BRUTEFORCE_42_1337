/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 15:22:44 by razaha            #+#    #+#             */
/*   Updated: 2020/01/04 23:17:18 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1 , &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int len;

	len = 0;
	while(*s != '\0')
	{
		len += ft_putchar(*s);
		s++;
	}
	return (len);
}

void	ft_putnbr(int n, int *ret)
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
		ft_putnbr(inb / 10, ret);
	*ret += 1;
	ft_putchar(inb % 10 + '0');
}
