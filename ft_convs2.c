/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:39:32 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/10 17:48:33 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		lowercase_hex_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char	*s1;

	if (LENGTHS == 1)
		ft_octals_hex(tools, vl);
	else
		NBR = va_arg(vl, uintmax_t);
	s1 = ft_itoa_base3(NBR, 16);
	NNBR = ft_atoi(s1);
	if ((((PREC == 0 && NBR == 0) && PW_EXIST == 1) || (PREC == 1 && NBR == 0)) && (FLAG == 0))
	{
		/*
		   ft_strclr(s1);
		   s1 = NULL;
		   PREC = 0;
		   LEN = 0;
		   if (WIDTH != 0)
		   ints_prec_or_width(tools, toolsone);
		   */
		s1 = ft_strnew(1);
		s1 = "0";
		PREC = 0;
		LEN = ft_strlen(s1);
		if (PERIPREC == 1)
			LEN = PREC;
		if (WIDTH != 0)
		{
			ints_prec_or_width(tools, toolsone);
		}
		if (PERIPREC != 1)
			ft_putstr(s1);
	}
	else 
	{
		ft_turn_to_lowercase(s1);
		/*
		   LEN = ft_strlen(s1);
		   if (MINUS == 1)
		   ft_minus_hash(s1, tools, toolsone);
		   ft_doing(tools, toolsone);
		   if (UNBR != 1)
		   ft_putstr(s1);
		   */
		LEN = ft_strlen(s1);
		if (HASH == 1 && NBR == 0)
			HASH = 0;
		if (ZERO == 1 && MINUS == 1)
			ZERO = 0;
		if ((PERIPREC == 1 && NBR == 0) && (HASH == 1))
		{
			LEN = PREC;
			HASH = 0;
			//LEN++;
		}
		if (MINUS == 1)
		{
			if (PERIPREC == 1)
				LEN = PREC;
			ft_minus_and_plus(s1, tools, toolsone);
		}
		/*
		   if (PERIPREC == 1)
		   {
		   LEN = PREC;
		   }
		   */
		ft_doing(tools, toolsone);
		if (UNBR != 1)
			ft_putstr(s1);
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
	//int		nlen;

	//nlen = 0;
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
	if (MINUS == 1)
		ft_minus_and_plus(s1, tools, toolsone);
	ft_doing(tools, toolsone);
	if (RETLEN != 0)
		RETLEN = LEN + RETLEN;
	else
		RETLEN = LEN;
	if (UNBR != 1)
		ft_putstr(s1);
	//nlen = RLEN;
	ft_bzero(tools, sizeof(t_conv));
	return (RETLEN);
}

int		pointers_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char		*s1;
	long long	p;
	//int			nlen;

	//nlen = 0;
	p = va_arg(vl, unsigned long long);
	s1 = ft_uitoa_base2(p, 16);
	LEN = ft_strlen(s1);
	LEN += 2;
	ft_turn_to_lowercase(s1);
	ft_doing(tools, toolsone);
	write(1, "0x", 2);
	if (RETLEN != 0)
		RETLEN = LEN + RETLEN;
	else
		RETLEN = LEN;
	//nlen = RLEN;
	ft_putstr(s1);
	ft_bzero(tools, sizeof(t_conv));
	return (RETLEN);
}

int		floats_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char		*s1;
	//int			nlen;
	//nlen = 0;
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
	//nlen = RLEN;
	ft_bzero(tools, sizeof(t_conv));
	return (RETLEN);
}
