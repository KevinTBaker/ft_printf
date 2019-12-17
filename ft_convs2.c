/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:39:32 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/16 18:21:14 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		lowercase_hex_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char	*s1;

	if (LENGTHS == 1)
		ft_octals_hex(tools, vl);
	else
		NBR = va_arg(vl, unsigned int);
	s1 = ft_itoa_base3(NBR, 16);
	NNBR = ft_atoi(s1);
	if ((((PREC == 0 && NBR == 0) && PW_EXIST == 1)
				|| (PREC == 1 && NBR == 0)) && (FLAG == 0))
		ft_nbr_and_prec_is_zero(s1, tools, toolsone);
	else
	{
		LEN = ft_strlen(s1);
		ft_turn_to_lowercase(s1);
		hexes_else_statement(s1, tools, toolsone);
	}
	if (RETLEN != 0)
		RETLEN = LEN + RETLEN;
	else
		RETLEN = LEN;
	ft_bzero(tools, sizeof(t_conv));
	return (RETLEN);
}

int		unsigned_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char	*s1;

	if (LENGTHS == 1)
		ft_unsigned_len(tools, vl);
	else
		NBR = va_arg(vl, unsigned int);
	s1 = ft_uitoa_base3(NBR, 10);
	LEN = ft_strlen(s1);
	if (PLUS == 1)
		PLUS = 0;
	if (SPACE == 1)
		SPACE = 0;
	if ((((PREC == 0 && NBR == 0) && PW_EXIST == 1) ||
				(PREC == 1 && NBR == 0)) && (FLAG == 0))
		ft_nbr_and_prec_is_zero(s1, tools, toolsone);
	else
		ft_nbr_and_prec_else(s1, tools, toolsone);
	if (RETLEN != 0)
		RETLEN = LEN + RETLEN;
	else
		RETLEN = LEN;
	ft_bzero(tools, sizeof(t_conv));
	return (RETLEN);
}

int		pointers_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char		*s1;
	long long	p;

	p = va_arg(vl, unsigned long long);
	s1 = ft_uitoa_base2(p, 16);
	LEN = ft_strlen(s1);
	LEN += 2;
	ft_turn_to_lowercase(s1);
	if (PREC != 0)
		PREC = 0;
	if (PERIPREC == 1)
	{
		LEN = PREC;
		LEN += 2;
	}
	ft_doing(tools, toolsone);
	write(1, "0x", 2);
	if (RETLEN != 0)
		RETLEN = LEN + RETLEN;
	else
		RETLEN = LEN;
	if (PERIPREC != 1)
		ft_putstr(s1);
	ft_bzero(tools, sizeof(t_conv));
	return (RETLEN);
}

int		floats_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char		*s1;

	if (LENGTHS == 1)
		ft_floats_ls(tools, vl);
	else
		F = va_arg(vl, double);
	NBR = F;
	if (!PREC)
		PREC = 6;
	s1 = ft_ldtoa(F, PREC);
	LEN = ft_strlen(s1);
	PREC = 0;
	ft_doing(tools, toolsone);
	if (RETLEN != 0)
		RETLEN = LEN + RETLEN;
	else
		RETLEN = LEN;
	ft_putstr(s1);
	ft_bzero(tools, sizeof(t_conv));
	return (RETLEN);
}
