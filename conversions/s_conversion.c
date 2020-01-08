
#include "../ft_printf.h"

void	sconversion(char *s)
{
	if (s == NULL)
		s = "(null)";
	if (flags.minus)
	{
		ft_putstr(s, flags.prec);
		ft_space(flags.width - ((flags.prec > ft_strlen(s)
		|| flags.prec == -1) ? ft_strlen(s) : flags.prec));
	}
	else
	{
		ft_space(flags.width - ((flags.prec > ft_strlen(s)
		|| flags.prec == -1) ? ft_strlen(s) : flags.prec));
		ft_putstr(s, flags.prec);
	}
}