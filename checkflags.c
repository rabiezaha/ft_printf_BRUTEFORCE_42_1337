/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:11:44 by razaha            #+#    #+#             */
/*   Updated: 2020/01/04 23:17:16 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_isconversion(char c)
{
	if (c == 's' || c == 'd')
		return (1);
	return (0);
}

int	ft_checkflags(char *fmt)
{
	int	jump;

	jump = 0;
	while(!ft_isconversion(*fmt) && *fmt != 0)
	{
		fmt++;
		jump++; 
	}
	if (!*fmt)
		return (0);	
	return (jump);
}
