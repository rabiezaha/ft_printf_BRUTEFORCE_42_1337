#include "../ft_printf.h"

void	uconversion2(unsigned int n, int n_len)
{
	if (flags.minus)
	{
		ft_zero(flags.zero - n_len);
		ft_putnbr(n);
		ft_space(flags.width - (flags.zero > n_len ? flags.zero : n_len));
	}
	else
	{
		ft_space(flags.width - (flags.zero > n_len ? flags.zero : n_len));
		ft_zero(flags.zero - n_len);
		ft_putnbr(n);
	}
}

void	uconversion(unsigned int n)
{
	int n_len;

	n_len = ft_nbrlen(n);
	if (flags.prec > -1)
	{
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
		flags.zero = flags.prec;
	}
	uconversion2(n, n_len);
}