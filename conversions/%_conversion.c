#include "../ft_printf.h"

void	prconversion(char c)
{
    if (flags.minus && flags.zero)
    {
        flags.width = flags.zero;
        flags.zero = 0;
    }
	if (flags.minus)
	{
        ft_zero(flags.zero - 1);
		ft_putchar(c);
		ft_space(flags.width - 1);
	}
	else
	{
		ft_space(flags.width - 1);
        ft_zero(flags.zero - 1);
		ft_putchar(c);
	}
}