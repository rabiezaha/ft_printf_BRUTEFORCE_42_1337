/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 21:42:41 by razaha            #+#    #+#             */
/*   Updated: 2020/01/09 01:21:52 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_space(int i)
{
	while (i-- > 0)
		ft_putchar(' ');
}

void	ft_zero(int i)
{
	while (i-- > 0)
		ft_putchar('0');
}

void	ft_resetstruct(void)
{
	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.prec = -1;
}

int		ft_isconversion(char c)
{
	if (c == 's' || c == 'd' || c == 'i' || c == 'c' || c == '%'
	|| c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return (1);
	return (0);
}

char	*skip_zero(char *fmt)
{
	flags.zero = ft_atoi(fmt);
	while (*fmt >= '0' && *fmt <= '9')
		fmt++;
	if (*fmt == '*')
		flags.zero = 1;
	return (fmt - 1);
}