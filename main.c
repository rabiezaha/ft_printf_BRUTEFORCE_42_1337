/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 14:49:09 by razaha            #+#    #+#             */
/*   Updated: 2020/01/04 23:17:05 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	main()
{
	//char s[] = "Hi , its me again ! recoding ft_printf , the blackhole still away ";
	int n;
	char s[] = "world";
	int nb = 100;
	n = printf("hello %s %d", s, nb);

	printf("\n%d", n);

	return 0;
}
