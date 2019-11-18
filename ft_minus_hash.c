#include "ft_printf.h"

void	ft_minus_hash(char *s1, t_conv *tools, t_convone *toolsone)
{
	if (LILO == 1 && HASH == 1)
	{
		write(1, "0", 1);
		LEN++;
	}
	else if (LILX == 1 && HASH == 1)
	{
		write(1, "0x", 2);
		LEN += 2;
	}
	ft_putstr(s1);
	FLAG = 0;
	MINUS = 0;
	HASH = 0;
	UNBR = 1;
}

void	minus_width(char *s1, t_conv *tools, t_convone *toolsone)
{
	//ft_putstr(s1);
	if (HASH == 1)
	{
		write(1, "0", 1);
		WIDTH--;
		HASH = 0;
		RETLEN++;
	}
	ft_putstr(s1);
	while (WIDTH > LEN)
	{
		write(1, " ", 1);
		WIDTH--;
		RETLEN++;
	}
	WIDTH = 0;
	UNBR = 1;
}

void	minus_prec_width(char *s1, t_conv *tools, t_convone *toolsone)
{
	if (!(PREC < LEN))
		PREC = PREC - LEN;
	WIDTH = WIDTH - PREC;
	while (PREC > 0)
	{
		write(1, "0", 1);
		PREC--;
		RETLEN++;
	}
	PREC = 0;
	ft_putstr(s1);
	WIDTH = WIDTH - LEN;
	while (WIDTH > 0)
	{
		write(1, " ", 1);
		WIDTH--;
		RETLEN++;
	}
	WIDTH = 0;
	UNBR = 1;
}
void	ft_minus_and_plus(char *s1, t_conv *tools, t_convone *toolsone)
{
	if (PLUS == 1)
	{
		if (NBR >= 0)
		{
			ft_putchar('+');
			WIDTH--;
			RETLEN++;
		}
		else 
			ft_putchar('-');
		PLUS = 0;
		UNBR = 1;
	}
	if ((PREC != 0 && WIDTH != 0) && (WIDTH > PREC)) 
		minus_prec_width(s1, tools, toolsone);
	if (!PREC && WIDTH)
		minus_width(s1, tools, toolsone);
	//if (PREC && !WIDTH)
	//	minus_prec(s1, tools, toolsone);
	//ints_width_and_precision(tools, toolsone);
	//main_width_and_prec(tools, toolsone);
	MINUS = 0;
}