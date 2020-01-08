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

void	prconversion(char c);
void	cconversion(char c);
void	sconversion(char *s);
void	dconversion(int n);
void	uconversion(unsigned int n);
void	xconversion(int n , int x);
void	pconversion(unsigned long n);
int	ft_isconversion(char c);

int	ft_strlen(const char *s);
void ft_putchar(char c);
void ft_putstr(char *s ,int i);
void ft_putnbr(long n);
void ft_puthex(unsigned int n, int x);
void ft_puthex_p(unsigned long n, int x);

int ft_atoi(char *str);
int	ft_nbrlen(int n);
int ft_hexlen(unsigned int n);
void ft_resetstruct();

void ft_space(int i);
void ft_zero(int i);

#endif
