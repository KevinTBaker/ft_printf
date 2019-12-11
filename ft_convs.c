/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:50:34 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/10 17:48:36 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		integers_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char	*s1;

	ft_deci_lengths_done(tools, vl);
	if ((NBR < 0 && ZERO == 1) || (NBR < 0 && PW_EXIST == 1))
		NBR = ft_turn_to_positive(tools);
	if (LENGTHS == 1)
		s1 = ft_itoa_base3(NBR, 10);	
	else
		s1 = ft_itoa_base2(NBR, 10);
	NNBR = ft_atoi(s1);
	if ((((PREC == 0 && NBR == 0) && PW_EXIST == 1) || (PREC == 1 && NBR == 0)) && (FLAG == 0))
	{
		s1 = ft_strnew(1);
		s1 = "0";
		PREC = 0;
		//turn len back to 0
		LEN = ft_strlen(s1);
		if (PERIPREC == 1)
			LEN = PREC;
		//LEN = 0;
		if (WIDTH != 0)
		{
			//	LEN = 1;
			ints_prec_or_width(tools, toolsone);
		}
		//LEN = 0;
		//take out PERIPREC
		if (PERIPREC != 1)
			ft_putstr(s1);
	}
	else
	{
		LEN = ft_strlen(s1);
		if ((PREC == 0 && NBR == 0) && PW_EXIST == 1)
		{
			s1 = ft_strnew(1);
			s1 = "0";
			PREC = 0;
			//turn len back to 0
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
	if (RETLEN != 0)
		RETLEN = LEN + RETLEN;
	else
		RETLEN = LEN;
	ft_bzero(tools, sizeof(t_conv));
	return (RETLEN);
}

int		octal_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char		*s1;

	if (LENGTHS == 1)
		ft_octals_hex(tools, vl);
	else
		NBR = va_arg(vl, uintmax_t);
	//if (LENGTHS == 1)
	//	s1 = ft_itoa_base3(NBR, 8);
	//else
	s1 = ft_itoa_base3(NBR, 8);
	NNBR = ft_atoi(s1);
	if ((((PREC == 0 && NBR == 0) && PW_EXIST == 1) || (PREC == 1 && NBR == 0)) && (FLAG == 0))
	{
		/*
		s1 = ft_strnew(1);
		s1 = "0";
		PREC = 0;
		LEN = ft_strlen(s1);
		if (HASH == 1)
			hash_width_and_prec(tools, toolsone);
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
	//{
		/*
		LEN = ft_strlen(s1);
		if ((PREC == 0 && NBR == 0) && PW_EXIST == 1)
		{
			s1 = ft_strnew(1);
			s1 = "0";
			PREC = 0;
			//turn len back to 0
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
	*/
	{
		LEN = ft_strlen(s1);
		if (HASH == 1 && NBR == 0)
			HASH = 0;
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

int		strings_done(t_conv *tools, t_convone *toolsone,  va_list vl)
{
	char	*s1;
	char	*s2;

	s1 = va_arg(vl, char*);
	s2 = NULL;
	if (s1 == NULL)
	{
		//ft_putstr("(null)");
		s1 = "(null)";
		LEN = ft_strlen(s1);
		if (PERIPREC == 1)
			LEN = PREC;
		//if (WIDTH != 0)
		//	main_width_and_prec(tools, toolsone);
		if (MINUS == 1)
			ft_minus_string_p_and_w(s1, s2, tools, toolsone);
		if (CONVS == 1)
			ft_doing(tools, toolsone);
		if (UNBR != 1)
		{
			s2 = ft_memalloc(LEN + 1);
			ft_strncpy(s2, s1, LEN);
			s2[LEN + 1] = '\0';
		}
		if (UNBR != 1 && PERIPREC != 1)
			ft_putstr(s2);
	}
	//s2 = NULL;
	else
	{
		s2 = NULL;
		LEN = ft_strlen(s1);
		if (PERIPREC == 1)
			LEN = PREC;
		if (MINUS == 1)
			ft_minus_string_p_and_w(s1, s2, tools, toolsone);
		if (CONVS == 1)
			ft_doing(tools, toolsone);
		if (UNBR != 1)
		{
			s2 = ft_memalloc(LEN + 1);
			ft_strncpy(s2, s1, LEN);
			s2[LEN + 1] = '\0';
		}
		if (UNBR != 1)
			ft_putstr(s2);
		/*
		   if (MNBR != 1)
		   {
		   s2 = ft_memalloc(LEN + 1);
		   ft_strncpy(s2, s1, LEN);
		   s2[LEN + 1] = '\0';
		   ft_putstr(s2);
		   }
		   */
	}
	if (RETLEN != 0)
		RETLEN = LEN + RETLEN;
	else
		RETLEN = LEN;
	/*
	   if (UNBR != 1)
	   ft_putstr(s2);
	   */
	ft_bzero(tools, sizeof(t_conv));
	return (RETLEN);
}

int		chars_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char	c;
	//int		nlen;

	//nlen = 0;
	c = va_arg(vl, int);
	LEN = 1;
	if (SPACE == 1)
		SPACE = 0;
	if (MINUS == 1)
		ft_putchar(c);
	ft_doing(tools, toolsone);
	if (RETLEN != 0)
		RETLEN = LEN + RETLEN;
	else
		RETLEN = LEN;
	if (UNBR != 1)
		ft_putchar(c);
	//nlen = RLEN;
	ft_bzero(tools, sizeof(t_conv));
	return (RETLEN);
}

int		uppercase_hex_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char	*s1;
	//int		nlen;

	//nlen = 0;
	//line 152 back to size_t
	//if (LENGTHS == 1)
	ft_octals_hex(tools, vl);
	//else
	//NBR = va_arg(vl, size_t);
	s1 = ft_uitoa_base3(NBR, 16);
	NNBR = ft_atoi(s1);
	LEN = ft_strlen(s1);
	if (PREC == 0 && NBR == 0)
	{
		s1 = ft_strnew(1);
		s1 = "0";
	}
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
