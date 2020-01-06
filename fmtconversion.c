/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmtconversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 12:37:35 by razaha            #+#    #+#             */
/*   Updated: 2020/01/06 18:51:25 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	strconversion(char *s)
{
	ft_putstr(s);
}

void	nbrconversion(int n)
{
	int n_len;

	n_len = ft_nbrlen(n);
	if (flags.minus == 0 && !flags.zero)
		ft_spaceleft(flags.width - n_len, n);
	 if (n < 0 && (flags.zero || flags.prec > -1))
	 {
        ft_putchar('-');
	 	flags.prec++;
	 }
	if (flags.zero)
		n_len += ft_zero(flags.width - n_len, n);
	if (flags.prec > -1)
		n_len += ft_zero(flags.prec - n_len, n);
	if (flags.minus)
		ft_spaceright(flags.width - n_len, n);

}
