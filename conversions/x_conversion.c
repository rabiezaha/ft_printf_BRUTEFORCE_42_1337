#include "../ft_printf.h"

void	xconversion2(unsigned int n, int n_len, int x)
{
	if (flags.minus)
	{
		ft_zero(flags.zero - n_len);
		ft_puthex(n, x);
		ft_space(flags.width - (flags.zero > n_len ? flags.zero : n_len));
	}
	else
	{
		ft_space(flags.width - (flags.zero > n_len ? flags.zero : n_len));
		ft_zero(flags.zero - n_len);
		ft_puthex(n, x);
	}
}

void	xconversion(unsigned int n, int x)
{
	int n_len;
	
	n_len = ft_hexlen(n);
	if (flags.prec > -1)
	{
		flags.width = (flags.zero ? flags.zero :flags.width);
		flags.zero = flags.prec;
		if (n == 0 && !flags.prec)
		{
			if (!flags.width)
				return ;
			ft_space(flags.width);
			return ;
		}
		if (flags.prec > flags.width)
		{
			if (flags.zero < 0)
				flags.minus = 1;
			flags.width = (flags.zero < 0 ? -flags.zero : flags.zero);
		}
	}
	xconversion2(n, n_len, x);
}