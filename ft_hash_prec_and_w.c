/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:18:18 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/17 16:50:37 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hash_width(t_conv *tools, t_convone *toolsone)
{
	if (tools->lil_o == 1)
		tools->width--;
	if (tools->zero == 1)
		ft_hash_width_zero_flag(tools, toolsone);
	if (tools->minus == 1)
	{
		write(1, "0x", 2);
		toolsone->retlen += 2;
		tools->hash = 0;
	}
	while (tools->width > tools->len && tools->zero == 0)
	{
		write(1, " ", 1);
		tools->width--;
		toolsone->retlen++;
	}
	tools->width = 0;
}

void	hash_width_and_prec(t_conv *tools, t_convone *toolsone)
{
	if (tools->lil_x || tools->big_x)
		tools->width -= 2;
	if (tools->prec == 1)
		tools->prec = tools->len;
	if (tools->lil_o)
		tools->width--;
	while (tools->width > tools->prec)
	{
		write(1, " ", 1);
		toolsone->retlen++;
		tools->width--;
	}
	tools->width = 0;
	if (tools->lil_o)
	{
		write(1, "0", 1);
		toolsone->retlen++;
	}
}

void	lilo_hash_width_and_prec(t_conv *tools, t_convone *toolsone)
{
	if (((tools->width == 0 && tools->prec == 0) && (tools->periprec == 0)))
	{
		write(1, "0", 1);
		tools->hash = 0;
	}
	if (tools->width != 0 && tools->prec != 0)
	{
		tools->len++;
		if (tools->prec < tools->len)
			tools->prec = tools->len;
		main_width_and_prec(tools, toolsone);
		write(1, "0", 1);
		tools->hash = 0;
		toolsone->retlen++;
	}
	if (tools->width && !tools->prec)
	{
		tools->width--;
		main_width_and_prec(tools, toolsone);
		write(1, "0", 1);
		toolsone->retlen++;
		tools->hash = 0;
	}
	lilo_no_width_hash_prec(tools);
}

void	lilx_hash_width_prec(t_conv *tools, t_convone *toolsone)
{
	if (tools->width && !tools->prec)
		tools->width -= 2;
	if (tools->width && !tools->prec)
		hash_width(tools, toolsone);
	if (tools->width != 0 && tools->prec != 0)
		hash_width_and_prec(tools, toolsone);
	if (tools->nnbr != 0 && tools->zero != 0)
		write(1, "0x", 2);
	if ((tools->width == 0 && tools->prec == 0) && (tools->hash == 1))
	{
		write(1, "0x", 2);
		toolsone->retlen += 2;
	}
}

void	bigx_hash_width_prec(t_conv *tools, t_convone *toolsone)
{
	if (tools->width && !tools->prec)
		tools->len += 2;
	if (tools->width && !tools->prec)
		hash_width(tools, toolsone);
	if (tools->width != 0 && tools->prec != 0)
		hash_width_and_prec(tools, toolsone);
	write(1, "0X", 2);
	toolsone->retlen += 2;
}
