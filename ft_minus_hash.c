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
		if (LILX == 1)
		{
			write(1, "x", 1);
			WIDTH--;
			RETLEN++;
		}
		else if (BIGX == 1)
		{
			write(1, "X", 1);
			WIDTH--;
			RETLEN++;
		}
		WIDTH--;
		HASH = 0;
		RETLEN++;
	}
	if (SPACE == 1)
	{
		//take out if back to NBR > 0
		if (NEG == 0)
		{
			write(1, " ", 1);
			WIDTH--;
		}
		SPACE = 0;
	}
	//if ((NBR != 0 && PREC != 0) && (PERIPREC != 1) && (LILO != 1))
	//if (LILO != 1)
	//if ((PW_EXIST != 1 && PREC != 0) && (PERIPREC != 1 && NBR != 0) && LILO != 1)
	if ((PERIPREC != 1 && NBR != 0))
		ft_putstr(s1);
	else if ((NBR == 0 && PREC == 0) && PERIPREC != 1)
		ft_putstr(s1);
	//else
	while (WIDTH > LEN)
	{
		write(1, " ", 1);
		WIDTH--;
		RETLEN++;
	}
	WIDTH = 0;
	UNBR = 1;
	//SPACE = 0;
}

void	minus_prec_width(char *s1, t_conv *tools, t_convone *toolsone)
{
	if (!(PREC < LEN))
		PREC = PREC - LEN;
	else if (LEN > PREC)
		PREC = 0;
	WIDTH = WIDTH - PREC;
	if (NEG == 1 && PREC == 0)
	{
		ft_putchar('-');
		NEG = 0;
		LEN++;
		//if (SPACE == 1)
		//	SPACE = 0;
	}
	if (SPACE == 1)
	{
		ft_putchar(' ');
		WIDTH--;
		SPACE = 0;
	}
	while (PREC > 0)
	{
		if (NEG == 1)
		{
			ft_putchar('-');
			NEG = 0;
			LEN++;
		}
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
		if (NBR >= 0 && NEG == 0)
		{
			ft_putchar('+');
			WIDTH--;
			RETLEN++;
		}
		/*
		else
		{
			ft_putchar('-');
			NEG = 0;
			//LEN++;
		}
		*/
		PLUS = 0;
		if (!(WIDTH > PREC))
			UNBR = 0;
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
