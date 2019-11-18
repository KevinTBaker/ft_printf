/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:50:34 by kbaker            #+#    #+#             */
/*   Updated: 2019/11/15 20:38:39 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		integers_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char	*s1;

	if (LENGTHS == 1)
		ft_deci_lengths_done(tools, vl);
	else
		NBR = va_arg(vl, int);
	if ((NBR < 0 && ZERO == 1) || (NBR < 0 && PW_EXIST == 1) /*&& (FLAG != 0))*/)
		NBR = ft_turn_to_positive(tools);
	s1 = ft_itoa(NBR);
	NNBR = ft_atoi(s1);
	LEN = ft_strlen(s1);
	if (MINUS == 1)
		ft_minus_and_plus(s1, tools, toolsone);
	//ft_putstr(s1);
	ft_doing(tools, toolsone);
	if (RETLEN != 0)
		RETLEN = LEN + RETLEN;
	else
		RETLEN = LEN;
	/*if (NEG == 1)
	{
		write(1, "-", 1);
		WIDTH--;
	}
	*/
	if (UNBR != 1)
		ft_putstr(s1);
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
	s1 = ft_itoa_base(NBR, 8);
	NNBR = ft_atoi(s1);
	LEN = ft_strlen(s1);
	if (MINUS == 1)
		ft_minus_and_plus(s1, tools, toolsone);
	ft_doing(tools, toolsone);
	if (RETLEN != 0)
		RETLEN = LEN + RETLEN;
	else
		RETLEN = LEN;
	//STRING = ft_strcpy(STRING, s1);
	if (UNBR != 1)
		ft_putstr(s1);
	//nlen = RLEN;
	ft_bzero(tools, sizeof(t_conv));
	return (RETLEN);
}

int		strings_done(t_conv *tools, t_convone *toolsone,  va_list vl)
{
	char	*s1;
	char	*s2;

	s1 = va_arg(vl, char*);
	//if (s1 == NULL)
	//	return NULL;
	s2 = NULL;
	LEN = ft_strlen(s1);
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
	/*
	if (MNBR != 1)
	{
		s2 = ft_memalloc(LEN + 1);
		ft_strncpy(s2, s1, LEN);
		s2[LEN + 1] = '\0';
		ft_putstr(s2);
	}
	*/
	if (RETLEN != 0)
		RETLEN = LEN + RETLEN;
	else
		RETLEN = LEN;
	if (UNBR != 1)
		ft_putstr(s2);
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
	if (LENGTHS == 1)
		ft_octals_hex(tools, vl);
	else
		NBR = va_arg(vl, uintmax_t);
	s1 = ft_itoa_base(NBR, 16);
	NNBR = ft_atoi(s1);
	LEN = ft_strlen(s1);
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
