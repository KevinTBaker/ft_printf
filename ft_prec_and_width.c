/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_and_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:42:30 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/17 20:04:46 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ints_width_and_precision(t_conv *tools, t_convone *toolsone)
{
	if (tools->prec && tools->width)
	{
		tools->wplus = 1;
		if_neg_or_plus(tools, toolsone);
		if (tools->prec == 1 || tools->prec == tools->len)
			tools->prec = tools->len;
		if (tools->len > tools->prec)
			tools->prec = tools->len;
		while (tools->width > tools->prec && toolsone->unbr != 1)
		{
			write(1, " ", 1);
			toolsone->retlen++;
			tools->width--;
		}
		if (tools->neg == 1)
		{
			ft_putchar('-');
			tools->neg = 0;
		}
		ints_width_and_precision2(tools, toolsone);
	}
}

void	ints_prec_or_width(t_conv *tools, t_convone *toolsone)
{
	if (tools->width)
	{
		if (tools->plus == 1 || tools->neg == 1)
			tools->len++;
		tools->width = tools->width - tools->len;
		while (tools->width > 0)
		{
			if (tools->zero == 1)
			{
				write(1, "0", 1);
				tools->zero = 0;
			}
			else
				write(1, " ", 1);
			tools->width--;
			toolsone->retlen++;
		}
		if_plus_or_neg(tools);
	}
	else if (tools->prec)
		ints_prec(tools, toolsone);
}

void	strings_width_and_prec(t_conv *tools, t_convone *toolsone)
{
	if (tools->width && tools->prec)
	{
		width_and_prec_if(tools, toolsone);
		if (!(tools->width < tools->prec))
		{
			while (tools->prec > tools->len)
			{
				write(1, " ", 1);
				tools->prec--;
				toolsone->retlen++;
			}
		}
		if (tools->len != 0)
			tools->len = tools->prec;
		tools->prec = 0;
	}
	else if (tools->width)
		width_and_prec_else_if(tools, toolsone);
	else if (tools->prec && tools->len != 0)
		tools->len = tools->prec;
	else if ((tools->prec == 0 && tools->pw_exist == 1)
			&& (toolsone->unbr == 0))
		tools->len = tools->prec;
}

void	main_width_and_prec(t_conv *tools, t_convone *toolsone)
{
	if (tools->lil_d == 1 || tools->lil_i == 1 ||
			tools->lil_o == 1 || tools->lil_x == 1 || tools->big_x == 1
			|| tools->lil_u == 1 || tools->lil_p == 1)
	{
		if (tools->prec && tools->width)
			ints_width_and_precision(tools, toolsone);
		else if (tools->prec || tools->width)
			ints_prec_or_width(tools, toolsone);
	}
	else if (tools->lil_s == 1)
	{
		if (tools->pw_exist == 1)
			strings_width_and_prec(tools, toolsone);
	}
}

void	precision_and_width_get_it(t_conv *tools, t_convone *toolsone)
{
	if (tools->lil_d == 1 || tools->lil_i == 1 ||
			tools->lil_o == 1 || tools->lil_x == 1 || tools->big_x == 1
			|| tools->lil_u == 1 || tools->lil_p == 1)
		main_width_and_prec(tools, toolsone);
	else if (tools->lil_s == 1)
		main_width_and_prec(tools, toolsone);
	else if (tools->lil_c == 1 || tools->dperc == 1)
		char_width(tools, toolsone);
}
