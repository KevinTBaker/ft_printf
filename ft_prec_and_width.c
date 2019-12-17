/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_and_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:42:30 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/16 20:08:03 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ints_width_and_precision(t_conv *tools, t_convone *toolsone)
{
	if (PREC && WIDTH)
	{
		WPLUS = 1;
		if_neg_or_plus(tools, toolsone);
		if (PREC == 1 || PREC == LEN)
			PREC = LEN;
		if (LEN > PREC)
			PREC = LEN;
		while (WIDTH > PREC && UNBR != 1)
		{
			write(1, " ", 1);
			RETLEN++;
			WIDTH--;
		}
		if (NEG == 1)
		{
			ft_putchar('-');
			NEG = 0;
		}
		ints_width_and_precision2(tools, toolsone);
	}
}

void	ints_prec_or_width(t_conv *tools, t_convone *toolsone)
{
	if (WIDTH)
	{
		if (PLUS == 1 || NEG == 1)
			LEN++;
		WIDTH = WIDTH - LEN;
		while (WIDTH > 0)
		{
			if (ZERO == 1)
			{
				write(1, "0", 1);
				ZERO = 0;
			}
			else
				write(1, " ", 1);
			WIDTH--;
			RETLEN++;
		}
		if_plus_or_neg(tools);
	}
	else if (PREC)
		ints_prec(tools, toolsone);
}

void	strings_width_and_prec(t_conv *tools, t_convone *toolsone)
{
	if (WIDTH && PREC)
	{
		width_and_prec_if(tools, toolsone);
		if (!(WIDTH < PREC))
		{
			while (PREC > LEN)
			{
				write(1, " ", 1);
				PREC--;
				RETLEN++;
			}
		}
		if (LEN != 0)
			LEN = PREC;
		PREC = 0;
	}
	else if (WIDTH)
		width_and_prec_else_if(tools, toolsone);
	else if (PREC && LEN != 0)
		LEN = PREC;
	else if ((PREC == 0 && PW_EXIST == 1) && (UNBR == 0))
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
