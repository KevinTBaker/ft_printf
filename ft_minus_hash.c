/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:35:36 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/16 18:48:26 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minus_hash(char *s1, t_conv *tools, t_convone *toolsone)
{
	if (tools->lil_o == 1 && tools->hash == 1)
	{
		write(1, "0", 1);
		tools->len++;
	}
	else if (tools->lil_x == 1 && tools->hash == 1)
	{
		write(1, "0x", 2);
		tools->len += 2;
	}
	ft_putstr(s1);
	tools->flag = 0;
	tools->minus = 0;
	tools->hash = 0;
	toolsone->unbr = 1;
}

void	minus_width(char *s1, t_conv *tools, t_convone *toolsone)
{
	if (tools->hash == 1)
		minus_width_hash(tools, toolsone);
	if (tools->space == 1)
	{
		if (tools->neg == 0)
		{
			write(1, " ", 1);
			tools->width--;
		}
		tools->space = 0;
	}
	if ((tools->periprec != 1 && tools->nbr != 0))
		ft_putstr(s1);
	else if ((tools->nbr == 0 && tools->prec == 0) && tools->periprec != 1)
		ft_putstr(s1);
	while (tools->width > tools->len)
	{
		write(1, " ", 1);
		tools->width--;
		toolsone->retlen++;
	}
	tools->width = 0;
	toolsone->unbr = 1;
}

void	minus_prec_width(char *s1, t_conv *tools, t_convone *toolsone)
{
	if (!(tools->prec < tools->len))
		tools->prec = tools->prec - tools->len;
	else if (tools->len > tools->prec)
		tools->prec = 0;
	tools->width = tools->width - tools->prec;
	minus_prec_width_space_neg(tools, toolsone);
	tools->prec = 0;
	ft_putstr(s1);
	tools->width = tools->width - tools->len;
	while (tools->width > 0)
	{
		write(1, " ", 1);
		tools->width--;
		toolsone->retlen++;
	}
	tools->width = 0;
	toolsone->unbr = 1;
}

void	ft_minus_and_plus(char *s1, t_conv *tools, t_convone *toolsone)
{
	if (tools->plus == 1)
	{
		if (tools->nbr >= 0 && tools->neg == 0)
		{
			ft_putchar('+');
			tools->width--;
			toolsone->retlen++;
		}
		tools->plus = 0;
		if (!(tools->width > tools->prec))
			toolsone->unbr = 0;
	}
	if ((tools->prec != 0 && tools->width != 0) && (tools->width > tools->prec))
		minus_prec_width(s1, tools, toolsone);
	if (!tools->prec && tools->width)
		minus_width(s1, tools, toolsone);
	tools->minus = 0;
}
