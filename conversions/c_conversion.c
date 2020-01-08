
#include "../ft_printf.h"

void	cconversion(char c)
{
	if (flags.minus)
	{
		ft_putchar(c);
		ft_space(flags.width - 1);
	}
	else
	{
		ft_space(flags.width - 1);
		ft_putchar(c);
	}
}