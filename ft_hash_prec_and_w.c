/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:18:18 by kbaker            #+#    #+#             */
/*   Updated: 2019/11/12 17:31:36 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hash_width(t_conv *tools, t_convone *toolsone)
{
	if (LILO == 1)
		WIDTH--;
	if (ZERO == 1)
	{
		write(1, "0x", 2);
		RETLEN += 2;
		while (WIDTH > LEN)
		{
			write(1, "0", 1);
			WIDTH--;
			RETLEN++;
		}
		ZERO = 0;
		HASH = 0;
		//NNBR = 1;
	}
	if (MINUS == 1)
	{
		//make a function for this
		write(1, "0x", 2);
		//put str
		RETLEN += 2;
		HASH = 0;
	}
	while (WIDTH > LEN && ZERO == 0)
	{
		write(1, " ", 1);
		WIDTH--;
		RETLEN++;
	}
	WIDTH = 0;
}

void	hash_width_and_prec(t_conv *tools, t_convone *toolsone)
{
	if (LILX || BIGX)
		WIDTH -= 2;
	if (PREC == 1)
		PREC = LEN;
	if (LILO)
		WIDTH--;
	while (WIDTH > PREC)
	{
		write(1, " ", 1);
		RETLEN++;
		WIDTH--;
	}
	WIDTH = 0;
	if (LILO)
	{
		write(1, "0", 1);
		RETLEN++;
	}
}

void	lilo_hash_width_and_prec(t_conv *tools, t_convone *toolsone)
{
	if (WIDTH != 0 && PREC != 0)
	{
		LEN++;
		if (PREC < LEN)
			PREC = LEN;
		main_width_and_prec(tools, toolsone);
		write(1, "0", 1);
		RETLEN++;
	}
	if (WIDTH && !PREC)
	{
		WIDTH--;
		main_width_and_prec(tools, toolsone);
		write(1, "0", 1);
		RETLEN++;
	}
	if (!WIDTH && PREC)
	{
		write(1, "0", 1);
		LEN++;
	}
}

void	lilx_hash_width_prec(t_conv *tools, t_convone *toolsone)
{
	if (WIDTH && !PREC)
		WIDTH -= 2;
	if (WIDTH && !PREC)
		hash_width(tools, toolsone);
	if (WIDTH != 0 && PREC != 0)
		hash_width_and_prec(tools, toolsone);
	if (NNBR != 0 && ZERO != 0)
	{
		write(1, "0x", 2);
		//if (!PW_EXIST)
		//	RETLEN += 2;
	}
	if ((WIDTH == 0 && PREC == 0) && (HASH == 1))
	{
		if (NNBR != 0)
		{
			write(1, "0x", 2);
			RETLEN += 2;
		}
	}
}

void	bigx_hash_width_prec(t_conv *tools, t_convone *toolsone)
{
	if (WIDTH && !PREC)
		LEN += 2;
	if (WIDTH && !PREC)
		hash_width(tools, toolsone);
	if (WIDTH != 0 && PREC != 0) 
		hash_width_and_prec(tools, toolsone);
	write(1, "0X", 2);
	//if (!WIDTH && PREC)
	RETLEN += 2;
}
