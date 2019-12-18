/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:50:34 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/17 20:00:24 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		integers_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char	*s1;

	ft_deci_lengths_done(tools, vl);
	if ((tools->nbr < 0 && tools->zero == 1) ||
			(tools->nbr < 0 && tools->pw_exist == 1))
		tools->nbr = ft_turn_to_positive(tools);
	if (tools->lengths == 1)
		s1 = ft_itoa_base3(tools->nbr, 10);
	else
		s1 = ft_itoa_base2(tools->nbr, 10);
	tools->nnbr = ft_atoi(s1);
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

int		octal_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char		*s1;

	if (tools->lengths == 1)
		ft_octals_hex(tools, vl);
	else
		tools->nbr = va_arg(vl, uintmax_t);
	s1 = ft_itoa_base3(tools->nbr, 8);
	tools->nnbr = ft_atoi(s1);
	if ((((tools->prec == 0 && tools->nbr == 0) && tools->pw_exist == 1) ||
				(tools->prec == 1 && tools->nbr == 0)) && (tools->flag == 0))
		ft_nbr_and_prec_is_zero(s1, tools, toolsone);
	else
		octal_else_statement(s1, tools, toolsone);
	if (toolsone->retlen != 0)
		toolsone->retlen = tools->len + toolsone->retlen;
	else
		toolsone->retlen = tools->len;
	ft_bzero(tools, sizeof(t_conv));
	return (toolsone->retlen);
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
	if (toolsone->retlen != 0)
		toolsone->retlen = tools->len + toolsone->retlen;
	else
		toolsone->retlen = tools->len;
	ft_bzero(tools, sizeof(t_conv));
	return (toolsone->retlen);
}

int		chars_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char	c;

	c = va_arg(vl, int);
	tools->len = 1;
	if (tools->space == 1)
		tools->space = 0;
	if (tools->minus == 1)
		ft_putchar(c);
	ft_doing(tools, toolsone);
	if (toolsone->retlen != 0)
		toolsone->retlen = tools->len + toolsone->retlen;
	else
		toolsone->retlen = tools->len;
	if (toolsone->unbr != 1)
		ft_putchar(c);
	ft_bzero(tools, sizeof(t_conv));
	return (toolsone->retlen);
}

int		uppercase_hex_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	char	*s1;

	if (tools->lengths == 1)
		ft_octals_hex(tools, vl);
	else
		tools->nbr = va_arg(vl, unsigned int);
	s1 = ft_itoa_base3(tools->nbr, 16);
	tools->nnbr = ft_atoi(s1);
	if ((((tools->prec == 0 && tools->nbr == 0) && tools->pw_exist == 1) ||
				(tools->prec == 1 && tools->nbr == 0)) && (tools->flag == 0))
		ft_nbr_and_prec_is_zero(s1, tools, toolsone);
	else
	{
		tools->len = ft_strlen(s1);
		hexes_else_statement(s1, tools, toolsone);
	}
	if (toolsone->retlen != 0)
		toolsone->retlen = tools->len + toolsone->retlen;
	else
		toolsone->retlen = tools->len;
	ft_bzero(tools, sizeof(t_conv));
	return (toolsone->retlen);
}
