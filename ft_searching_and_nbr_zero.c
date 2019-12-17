/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searching.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:06:50 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/16 17:12:02 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_search(char c)
{
	if (c == '#' || c == ' ' || c == '0' || c == '+' || c == '-')
		return (1);
	else
		return (0);
}

void	plus_and_space_if_nbr_is_positive(t_conv *tools, t_convone *toolsone)
{
	if (NBR >= 0 && NEG == 0)
	{
		if ((PREC && !WIDTH) || (!PREC && !WIDTH))
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

void	space_if_nbr_is_positive(t_conv *tools, t_convone *toolsone)
{
	if ((NBR >= 0 && UNBR == 0) && NEG == 0)
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
		if (!PREC && WIDTH)
		{
			ft_putchar(' ');
			WIDTH--;
			RETLEN++;
		}
		main_width_and_prec(tools, toolsone);
	}
	SPACE = 0;
}

void	ft_nbr_and_prec_is_zero(char *s1, t_conv *tools, t_convone *toolsone)
{
	s1 = ft_strnew(1);
	s1 = "0";
	PREC = 0;
	LEN = ft_strlen(s1);
	if (PERIPREC == 1)
		LEN = PREC;
	if (WIDTH != 0)
		ints_prec_or_width(tools, toolsone);
	if (PERIPREC != 1)
		ft_putstr(s1);
}

void	ft_nbr_and_prec_else(char *s1, t_conv *tools, t_convone *toolsone)
{
	LEN = ft_strlen(s1);
	if ((PREC == 0 && NBR == 0) && PW_EXIST == 1)
	{
		s1 = ft_strnew(1);
		s1 = "0";
		PREC = 0;
		LEN = ft_strlen(s1);
		if (PERIPREC == 1)
		{
			UNBR = 1;
			if (PLUS == 1 && MINUS == 1)
			{
				PLUS = 0;
				ft_putchar('+');
				WIDTH--;
			}
			LEN = PREC;
			MINUS = 0;
		}
	}
	if (MINUS == 1 && PERIPREC == 0)
		ft_minus_and_plus(s1, tools, toolsone);
	ft_doing(tools, toolsone);
	if (UNBR != 1)
		ft_putstr(s1);
}
