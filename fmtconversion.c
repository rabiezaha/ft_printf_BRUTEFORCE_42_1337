#include "ft_printf.h"

int	strconversion(char *s)
{
	return (ft_putstr(s));
}

int nbrconversion(int n)
{
	int ret;

	ret = 0;
	ft_putnbr(n, &ret);
	return (ret);
}
