#include "ft_printf.h"

int gather_doubleperc(char *str, int i, t_conv *tools)
{
	if (str[i] == '%')
		D_PERC = 1;
	PERC = 0;
	return (i);
}

int double_perc_done(t_conv *tools, t_convone *toolsone)
{
	char c;

	c = '%';
	LEN = 1;
	if (MINUS == 1)
		ft_putchar(c);
	ft_doing(tools, toolsone);
	if (RETLEN != 0)
		RETLEN = LEN + RETLEN;
	else
		RETLEN = LEN;
	if (UNBR != 1)
		ft_putchar(c);
	ft_bzero(tools, sizeof(t_conv));
	return (RETLEN);
}
