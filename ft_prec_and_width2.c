/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_and_width2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:16:10 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/16 17:08:50 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ints_width_and_precision2(t_conv *tools, t_convone *toolsone)
{
	if (tools->plus == 1)
		ft_putchar('+');
	if ((tools->space == 1) && (tools->width < tools->prec))
	{
		ft_putchar(' ');
		toolsone->retlen++;
	}
	tools->width = 0;
	tools->prec = tools->prec - tools->len;
	while (tools->prec > 0)
	{
		write(1, "0", 1);
		tools->prec--;
		toolsone->retlen++;
	}
	tools->prec = 0;
}

void	ints_prec(t_conv *tools, t_convone *toolsone)
{
	if (tools->neg == 1)
	{
		write(1, "-", 1);
		tools->neg = 0;
		toolsone->retlen++;
	}
	tools->prec = tools->prec - tools->len;
	while (tools->prec > 0)
	{
		write(1, "0", 1);
		tools->prec--;
		toolsone->retlen++;
	}
}

void	char_width(t_conv *tools, t_convone *toolsone)
{
	if (tools->width)
	{
		tools->width = tools->width - tools->len;
		while (tools->width > 0)
		{
			write(1, " ", 1);
			tools->width--;
			toolsone->retlen++;
		}
		tools->width = 0;
	}
}
