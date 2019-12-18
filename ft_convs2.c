/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:39:32 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/17 15:19:15 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		lowercase_hex_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char	*s1;

	if (tools->lengths == 1)
		ft_octals_hex(tools, vl);
	else
		tools->nbr = va_arg(vl, unsigned int);
	s1 = ft_itoa_base3(tools->nbr, 16);
	tools->nnbr = ft_atoi(s1);
	if ((((tools->prec == 0 && tools->nbr == 0) && tools->pw_exist == 1)
				|| (tools->prec == 1 && tools->nbr == 0)) && (tools->flag == 0))
		ft_nbr_and_prec_is_zero(s1, tools, toolsone);
	else
	{
		tools->len = ft_strlen(s1);
		ft_turn_to_lowercase(s1);
		hexes_else_statement(s1, tools, toolsone);
	}
	if (toolsone->retlen != 0)
		toolsone->retlen = tools->len + toolsone->retlen;
	else
		toolsone->retlen = tools->len;
	ft_bzero(tools, sizeof(t_conv));
	return (toolsone->retlen);
}

int		unsigned_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char	*s1;

	if (tools->lengths == 1)
		ft_unsigned_len(tools, vl);
	else
		tools->nbr = va_arg(vl, unsigned int);
	s1 = ft_uitoa_base3(tools->nbr, 10);
	tools->len = ft_strlen(s1);
	if (tools->plus == 1)
		tools->plus = 0;
	if (tools->space == 1)
		tools->space = 0;
	if ((((tools->prec == 0 && tools->nbr == 0) && tools->pw_exist == 1) ||
				(tools->prec == 1 && tools->nbr == 0)) && (tools->flag == 0))
		ft_nbr_and_prec_is_zero(s1, tools, toolsone);
	else
		ft_nbr_and_prec_else(s1, tools, toolsone);
	if (toolsone->retlen != 0)
		toolsone->retlen = tools->len + toolsone->retlen;
	else
		toolsone->retlen = tools->len;
	ft_bzero(tools, sizeof(t_conv));
	return (toolsone->retlen);
}

int		pointers_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char		*s1;
	long long	p;

	p = va_arg(vl, unsigned long long);
	s1 = ft_uitoa_base2(p, 16);
	tools->len = ft_strlen(s1);
	tools->len += 2;
	ft_turn_to_lowercase(s1);
	if (tools->prec != 0)
		tools->prec = 0;
	if (tools->periprec == 1)
	{
		tools->len = tools->prec;
		tools->len += 2;
	}
	ft_doing(tools, toolsone);
	write(1, "0x", 2);
	if (toolsone->retlen != 0)
		toolsone->retlen = tools->len + toolsone->retlen;
	else
		toolsone->retlen = tools->len;
	if (tools->periprec != 1)
		ft_putstr(s1);
	ft_bzero(tools, sizeof(t_conv));
	return (toolsone->retlen);
}

int		floats_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char		*s1;

	if (tools->lengths == 1)
		ft_floats_ls(tools, vl);
	else
		tools->flnbr = va_arg(vl, double);
	tools->nbr = tools->flnbr;
	if (!tools->prec)
		tools->prec = 6;
	s1 = ft_ldtoa(tools->flnbr, tools->prec);
	tools->len = ft_strlen(s1);
	tools->prec = 0;
	ft_doing(tools, toolsone);
	if (toolsone->retlen != 0)
		toolsone->retlen = tools->len + toolsone->retlen;
	else
		toolsone->retlen = tools->len;
	ft_putstr(s1);
	ft_bzero(tools, sizeof(t_conv));
	return (toolsone->retlen);
}
