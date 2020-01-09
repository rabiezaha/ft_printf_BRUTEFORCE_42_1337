/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 01:26:02 by razaha            #+#    #+#             */
/*   Updated: 2020/01/09 01:26:28 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

int		ft_nbrlen(long n)
{
	int				nbrlen;
	unsigned int	inb;

	nbrlen = 0;
	if (n < 0)
	{
		nbrlen++;
		inb = n * -1;
	}
	else
		inb = n;
	if (inb > 9)
		return (nbrlen + ft_nbrlen(inb / 10) + 1);
	return (nbrlen + 1);
}

int		ft_hexlen(unsigned int n)
{
	if (n > 15)
	{
		return (ft_hexlen(n / 16) + 1);
	}
	return (1);
}

int		ft_hexlen_p(unsigned long n)
{
	if (n > 15)
	{
		return (ft_hexlen_p(n / 16) + 1);
	}
	return (1);
}
