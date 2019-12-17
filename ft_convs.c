/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:50:34 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/16 18:20:30 by kbaker           ###   ########.fr       */
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

int		octal_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char		*s1;

	if (LENGTHS == 1)
		ft_octals_hex(tools, vl);
	else
		NBR = va_arg(vl, uintmax_t);
	s1 = ft_itoa_base3(NBR, 8);
	NNBR = ft_atoi(s1);
	if ((((PREC == 0 && NBR == 0) && PW_EXIST == 1) ||
				(PREC == 1 && NBR == 0)) && (FLAG == 0))
		ft_nbr_and_prec_is_zero(s1, tools, toolsone);
	else
		octal_else_statement(s1, tools, toolsone);
	if (RETLEN != 0)
		RETLEN = LEN + RETLEN;
	else
		RETLEN = LEN;
	ft_bzero(tools, sizeof(t_conv));
	return (RETLEN);
}

int		strings_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char	*s1;
	char	*s2;

	s1 = va_arg(vl, char*);
	s2 = NULL;
	if (s1 == NULL)
		strings_if_statement(s1, s2, tools, toolsone);
	else
		string_else_statement(s1, s2, tools, toolsone);
	if (RETLEN != 0)
		RETLEN = LEN + RETLEN;
	else
		RETLEN = LEN;
	ft_bzero(tools, sizeof(t_conv));
	return (RETLEN);
}

int		chars_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char	c;

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
	ft_bzero(tools, sizeof(t_conv));
	return (RETLEN);
}

int		uppercase_hex_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char	*s1;

	if (LENGTHS == 1)
		ft_octals_hex(tools, vl);
	else
		NBR = va_arg(vl, unsigned int);
	s1 = ft_itoa_base3(NBR, 16);
	NNBR = ft_atoi(s1);
	if ((((PREC == 0 && NBR == 0) && PW_EXIST == 1) ||
				(PREC == 1 && NBR == 0)) && (FLAG == 0))
		ft_nbr_and_prec_is_zero(s1, tools, toolsone);
	else
	{
		LEN = ft_strlen(s1);
		hexes_else_statement(s1, tools, toolsone);
	}
	if (RETLEN != 0)
		RETLEN = LEN + RETLEN;
	else
		RETLEN = LEN;
	ft_bzero(tools, sizeof(t_conv));
	return (RETLEN);
}
