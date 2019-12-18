/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:45:47 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/17 16:05:53 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lilo_no_width_hash_prec(t_conv *tools)
{
	if (!tools->width && tools->prec)
	{
		write(1, "0", 1);
		tools->len++;
	}
}

void	hexes_else_statement(char *s1, t_conv *tools, t_convone *toolsone)
{
	if (tools->hash == 1 && tools->nbr == 0)
	{
		tools->hash = 0;
		if (tools->periprec == 1)
		{
			tools->len = tools->prec;
			toolsone->unbr = 1;
		}
	}
	if (tools->zero == 1 && tools->minus == 1)
		tools->zero = 0;
	if ((tools->periprec == 1 && tools->nbr == 0) && (tools->hash == 1))
	{
		tools->len = tools->prec;
		tools->hash = 0;
	}
	if (tools->minus == 1)
	{
		if (tools->periprec == 1)
			tools->len = tools->prec;
		ft_minus_and_plus(s1, tools, toolsone);
	}
	ft_doing(tools, toolsone);
	if (toolsone->unbr != 1)
		ft_putstr(s1);
}

void	strings_if_statement(char *s1, char *s2,
		t_conv *tools, t_convone *toolsone)
{
	s1 = "(null)";
	tools->len = ft_strlen(s1);
	if (tools->periprec == 1)
		tools->len = tools->prec;
	if (tools->minus == 1)
		ft_minus_string_p_and_w(s1, s2, tools, toolsone);
	if (tools->convs == 1)
		ft_doing(tools, toolsone);
	if (toolsone->unbr != 1)
	{
		s2 = ft_memalloc(tools->len + 1);
		ft_strncpy(s2, s1, tools->len);
		s2[tools->len + 1] = '\0';
	}
	if (toolsone->unbr != 1 && tools->periprec != 1)
		ft_putstr(s2);
}

void	octal_else_statement(char *s1, t_conv *tools, t_convone *toolsone)
{
	tools->len = ft_strlen(s1);
	if (tools->hash == 1 && tools->nbr == 0)
		tools->hash = 0;
	if ((tools->periprec == 1 && tools->nbr == 0) && (tools->hash == 1))
	{
		tools->len = tools->prec;
		tools->hash = 0;
	}
	if (tools->minus == 1)
	{
		if (tools->periprec == 1)
			tools->len = tools->prec;
		ft_minus_and_plus(s1, tools, toolsone);
	}
	ft_doing(tools, toolsone);
	if (toolsone->unbr != 1)
		ft_putstr(s1);
}

void	string_else_statement(char *s1, char *s2,
		t_conv *tools, t_convone *toolsone)
{
	s2 = NULL;
	tools->len = ft_strlen(s1);
	if (tools->periprec == 1)
		tools->len = tools->prec;
	if (tools->minus == 1)
		ft_minus_string_p_and_w(s1, s2, tools, toolsone);
	if (tools->convs == 1)
		ft_doing(tools, toolsone);
	if (toolsone->unbr != 1)
	{
		s2 = ft_memalloc(tools->len + 1);
		ft_strncpy(s2, s1, tools->len);
		s2[tools->len + 1] = '\0';
	}
	if (toolsone->unbr != 1)
		ft_putstr(s2);
}
