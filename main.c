/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 14:49:09 by razaha            #+#    #+#             */
/*   Updated: 2020/01/05 22:25:27 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	main()
{
	//char s[] = "Hi , its me again ! recoding ft_printf , the blackhole still away ";
	int n;
	int m;
//	int nb = 100;
	n = ft_printf("black hole away %-5d  %*d %05d\n", 103 , -7 , 1337, 42);
	m = printf("black hole away %-5d  %*d %05d\n", 103 , -7 , 1337, 42);
	printf("\n%d\n%d", n, m);

	return 0;
}
