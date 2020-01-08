/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:06:54 by razaha            #+#    #+#             */
/*   Updated: 2020/01/08 23:51:45 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_resetstruct()
{
	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.prec = -1;
}

int ft_isconversion(char c)
{
	if(c == 's' || c == 'd' || c == 'i' || c == 'c' || c == '%' 
	|| c == 'u' || c == 'x'|| c == 'X' || c == 'p')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int sign;
	int res;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			res = res * 10 + *str - 48;
		else
			return (res * sign);
		str++;
	}
	return (res * sign);
}

int ft_nbrlen(long n)
{
	int nbrlen;
	unsigned int inb;

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
	return (nbrlen + 1) ;
}

int ft_hexlen(unsigned int n)
{
	if (n > 15)
	{
		return (ft_hexlen(n/16) + 1);
	}
	return (1);
}

int ft_hexlen_p(unsigned long n)
{
	if (n > 15)
	{
		return (ft_hexlen_p(n/16) + 1);
	}
	return (1);
}
