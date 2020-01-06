#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int	g_ret;
va_list g_args;

typedef	struct s_flag
{
	int minus;
	int zero;
	int width;
	int prec;
} t_flag;

t_flag flags;

int	ft_printf(const char *fmt, ...);
char *ft_checkflags(char *fmt);
void	strconversion(char *s);
void nbrconversion(int n);

int	ft_isconversion(char c);
void ft_putchar(char c);
void ft_putstr(char *s);
void ft_putnbr(int n);
int ft_atoi(char *str);
int	ft_nbrlen(int n);
void ft_resetstruct();

void ft_space(int i);
void ft_zero(int i);

#endif
