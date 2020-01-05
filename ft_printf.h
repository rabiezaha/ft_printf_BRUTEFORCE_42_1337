#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int	g_ret;
int g_nbrlen;
va_list g_args;

typedef	struct s_flag
{
	int minus;
	int zero;
	int width;
	int prec;
} t_flag;

t_flag flags;

typedef struct s_len
{
	int widthlen;
	int precilen;
}	t_len;

t_len lens;

int	ft_printf(const char *fmt, ...);
int	ft_checkflags(char *fmt);
void	strconversion(char *s);
void nbrconversion(int n);

int	ft_isconversion(char c);
void ft_putchar(char c);
void ft_putstr(char *s);
void ft_putnbr(int n);
int ft_atoi(char *str);
void	ft_nbrlen(int n);
void ft_resetstruct();

void ft_spaceleft(int i, int n);
void ft_spaceright(int i, int n);
void ft_zero(int i, int n);

#endif

