/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:45:47 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/16 17:08:02 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lilo_no_width_hash_prec(t_conv *tools)
{
	if (!WIDTH && PREC)
	{
		write(1, "0", 1);
		LEN++;
	}
}

void	hexes_else_statement(char *s1, t_conv *tools, t_convone *toolsone)
{
	if (HASH == 1 && NBR == 0)
	{
		HASH = 0;
		if (PERIPREC == 1)
		{
			LEN = PREC;
			UNBR = 1;
		}
	}
	if (ZERO == 1 && MINUS == 1)
		ZERO = 0;
	if ((PERIPREC == 1 && NBR == 0) && (HASH == 1))
	{
		LEN = PREC;
		HASH = 0;
	}
	if (MINUS == 1)
	{
		if (PERIPREC == 1)
			LEN = PREC;
		ft_minus_and_plus(s1, tools, toolsone);
	}
	ft_doing(tools, toolsone);
	if (UNBR != 1)
		ft_putstr(s1);
}

void	strings_if_statement(char *s1, char *s2,
		t_conv *tools, t_convone *toolsone)
{
	s1 = "(null)";
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
	if (UNBR != 1 && PERIPREC != 1)
		ft_putstr(s2);
}

void	octal_else_statement(char *s1, t_conv *tools, t_convone *toolsone)
{
	LEN = ft_strlen(s1);
	if (HASH == 1 && NBR == 0)
		HASH = 0;
	if ((PERIPREC == 1 && NBR == 0) && (HASH == 1))
	{
		LEN = PREC;
		HASH = 0;
	}
	if (MINUS == 1)
	{
		if (PERIPREC == 1)
			LEN = PREC;
		ft_minus_and_plus(s1, tools, toolsone);
	}
	ft_doing(tools, toolsone);
	if (UNBR != 1)
		ft_putstr(s1);
}

void	string_else_statement(char *s1, char *s2,
		t_conv *tools, t_convone *toolsone)
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
}
