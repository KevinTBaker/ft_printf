/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:03:00 by kbaker            #+#    #+#             */
/*   Updated: 2019/11/19 20:45:58 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hash_flag_done(t_conv *tools, t_convone *toolsone)
{
	if (HASH == 1)
	{
		if (LILO == 1)
			lilo_hash_width_and_prec(tools, toolsone);
		else if (LILX == 1)
			lilx_hash_width_prec(tools, toolsone);
		else if (BIGX == 1)
			bigx_hash_width_prec(tools, toolsone);
		HASH = 0;
		DHASH = 1;
	}
}

void	zero_flag_done(t_conv *tools, t_convone *toolsone)
{
	if (NEG == 1)
	{
		write(1, "-", 1);
		//check this len
		if (WIDTH != 0)
			LEN++;
		NEG = 0;
	}
	if (WIDTH != 0)
		WIDTH = WIDTH - LEN;
	while (WIDTH > 0)
	{
		write(1, "0", 1);
		WIDTH--;
		RETLEN++;
	}
	main_width_and_prec(tools, toolsone);
	ZERO = 0;
	WIDTH = 0;
}

void	plus_and_space_flag_done(t_conv *tools, t_convone *toolsone)
{
	if (PLUS == 1)
	{
		if (NBR >= 0 && NEG == 0)
		{
			if ((PREC && !WIDTH) || (!PREC &&!WIDTH))
			{
				ft_putchar('+');
				RETLEN++;
			}
			else if (ZERO == 1) 
			{
				ft_putchar('+');
				WIDTH--;
				RETLEN++;
				zero_flag_done(tools, toolsone);
			}
			main_width_and_prec(tools, toolsone);
		}
		PLUS = 0;
	}
	else if (SPACE == 1 && D_PERC == 0)
	{
		if (NBR >= 0)
		{
			if (PREC && !WIDTH)
			{
				ft_putchar(' ');
				RETLEN++;
			}
			if (!PREC && !WIDTH)
			{
				ft_putchar(' ');
				RETLEN++;
			}
			main_width_and_prec(tools, toolsone);
		}
		SPACE = 0;
	}
	PERC = 0;
}

void	minus_flag_done(t_conv *tools, t_convone *toolsone)
{
	if (WIDTH != 0)
		UNBR = 1;
	else
		main_width_and_prec(tools, toolsone);
}

void	flags_get_done(t_conv *tools, t_convone *toolsone)
{
	if ((PREC != 0 && WIDTH != 0) && (ZERO == 1))
		ZERO = 0;
	if (HASH == 1)
		hash_flag_done(tools, toolsone);
	else if (PLUS == 1)
		plus_and_space_flag_done(tools, toolsone);
	else if (SPACE == 1)
		plus_and_space_flag_done(tools, toolsone);
	if (ZERO == 1)
		zero_flag_done(tools, toolsone);
	else if (MINUS == 1)
		minus_flag_done(tools, toolsone);
}
