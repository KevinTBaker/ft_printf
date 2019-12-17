/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:35:36 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/16 18:48:26 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (HASH == 1)
		minus_width_hash(tools, toolsone);
	if (SPACE == 1)
	{
		if (NEG == 0)
		{
			write(1, " ", 1);
			WIDTH--;
		}
		SPACE = 0;
	}
	if ((PERIPREC != 1 && NBR != 0))
		ft_putstr(s1);
	else if ((NBR == 0 && PREC == 0) && PERIPREC != 1)
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
	else if (LEN > PREC)
		PREC = 0;
	WIDTH = WIDTH - PREC;
	minus_prec_width_space_neg(tools, toolsone);
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
		PLUS = 0;
		if (!(WIDTH > PREC))
			UNBR = 0;
	}
	if ((PREC != 0 && WIDTH != 0) && (WIDTH > PREC))
		minus_prec_width(s1, tools, toolsone);
	if (!PREC && WIDTH)
		minus_width(s1, tools, toolsone);
	MINUS = 0;
}
