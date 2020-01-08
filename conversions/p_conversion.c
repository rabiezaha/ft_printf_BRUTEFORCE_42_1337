#include "../ft_printf.h"

void	pconversion2(unsigned long n, int n_len)
{
	if (flags.minus)
	{
        ft_putstr("0x",2);
		ft_zero(flags.zero - n_len);
		ft_puthex_p(n, 0);
		ft_space(flags.width - (flags.zero > n_len ? flags.zero : n_len));
	}
	else
	{
		ft_space(flags.width - (flags.zero > n_len ? flags.zero : n_len));
        ft_putstr("0x",2);
		ft_zero(flags.zero - n_len);
		ft_puthex_p(n, 0);
	}
}

void	pconversion(unsigned long n)
{
	int n_len;

	n_len = ft_hexlen(n) + 2;
	if (flags.prec > -1)
	{
		if (n == 0 && !flags.prec)
		{
			if (!flags.width)
            {
                ft_putstr("0x",2);
				return ;
            }
            if (flags.minus)
            {
                ft_putstr("0x",2);
                ft_space(flags.width - 2);
            }
            else
            {
                ft_space(flags.width - 2);
                ft_putstr("0x",2);
            }
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
	pconversion2(n, n_len);
}