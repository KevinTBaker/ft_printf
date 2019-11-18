/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_and_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:42:30 by kbaker            #+#    #+#             */
/*   Updated: 2019/11/15 14:17:34 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ints_width_and_precision(t_conv *tools, t_convone *toolsone)
{
	if (PREC && WIDTH)
	{
		WPLUS = 1;
		if (NEG == 1)
		{
			write(1, "-", 1);
			NEG = 0;
			RETLEN++;
			WIDTH--;
		}
		if (PLUS == 1)
		{
			WIDTH--;
			RETLEN++;
		}
		if (PREC == 1 || PREC == LEN)
			PREC = LEN;
		//PREC = LEN;
		if (LEN > PREC)
			PREC = LEN;
		//PREC = 0;
		while (WIDTH > PREC && UNBR != 1)
		{
			write(1, " ", 1);
			RETLEN++;
			WIDTH--;
		}
		/*
		WIDTH = WIDTH - LEN;
		while (WIDTH > 0)
		{
			write(1, " ", 1);
			WIDTH--;
			RETLEN++;
		}
		*/
		ints_width_and_precision2(tools, toolsone);
	}
}

void	ints_prec_or_width(t_conv *tools, t_convone *toolsone)
{
	if (WIDTH)
	{
		if (PLUS == 1 || NEG == 1)
			LEN++;
		//if (NEG == 1)
		//	LEN++;
		WIDTH = WIDTH - LEN;
		while (WIDTH > 0)
		{
			write(1, " ", 1);
			WIDTH--;
			RETLEN++;
		}
		if (PLUS == 1)
			ft_putchar('+');
		if (NEG == 1)
			ft_putchar('-');
		WPLUS = 1;
	}
	else if (PREC)
		ints_prec(tools, toolsone);
}

void	strings_width_and_prec(t_conv *tools, t_convone *toolsone)
{
	if (WIDTH && PREC)
	{
		if (LEN == 0 && PREC > LEN)
		{
			LEN = PREC;
			PREC = 0;
		}
			//PREC = PREC - LEN;
			//LEN = PREC;
		//if (PREC > LEN)
		//	LEN = PREC;
			//PREC = PREC - LEN;
		//if (LEN != 0)
		//	WIDTH = WIDTH - PREC;
		//if (PREC > 0)
		//	LEN = PREC;
		while (WIDTH > PREC)
		{
			write(1, " ", 1);
			WIDTH--;
			RETLEN++;
		}
		if (LEN != 0)
			LEN = PREC;
		PREC = 0;
		//if (LEN == 0 && PREC > LEN)
		//	LEN = PREC;
	}
	else if (WIDTH)
	{
		while (WIDTH > LEN)
		{
			write(1, " ", 1);
			WIDTH--;
			RETLEN++;
		}
	}
	else if (PREC && LEN != 0)
		LEN = PREC;
}

void	main_width_and_prec(t_conv *tools, t_convone *toolsone)
{
	if (LILD == 1 || LILI == 1 || LILO == 1 || LILX == 1 || BIGX == 1
			|| LILU == 1 || LILP == 1)
	{
		if (PREC && WIDTH)
			ints_width_and_precision(tools, toolsone);
		else if (PREC || WIDTH)
			ints_prec_or_width(tools, toolsone);
	}
	else if (LILS == 1)
	{
		if (PW_EXIST == 1)
			strings_width_and_prec(tools, toolsone);
	}
}

void	precision_and_width_get_it(t_conv *tools, t_convone *toolsone)
{
	if (LILD == 1 || LILI == 1 || LILO == 1 || LILX == 1 || BIGX == 1
			|| LILU == 1 || LILP == 1)
		main_width_and_prec(tools, toolsone);
	else if (LILS == 1)
		main_width_and_prec(tools, toolsone);
	else if (LILC == 1 || D_PERC == 1)
		char_width(tools, toolsone);
}
