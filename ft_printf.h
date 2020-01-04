#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>


int	ft_printf(const char *fmt, ...);
int	ft_checkflags(char *fmt);
int	strconversion(char *s);
int nbrconversion(int n);

int ft_putchar(char c);
int ft_putstr(char *s);
void ft_putnbr(int n, int *ret);

#endif

