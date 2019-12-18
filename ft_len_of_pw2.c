/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_of_pw2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:18:35 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/16 20:25:30 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_len_of_pw_w(int n, int len, t_conv *tools)
{
	n = tools->width;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
}

void	width_and_prec_if(t_conv *tools, t_convone *toolsone)
{
	if (tools->len == 0 && tools->prec > tools->len)
	{
		tools->len = tools->prec;
		tools->prec = 0;
	}
	if (tools->prec == tools->width)
	{
		while (tools->prec > tools->len)
		{
			write(1, " ", 1);
			tools->prec--;
		}
		tools->width = 0;
	}
	while (tools->width > tools->prec)
	{
		write(1, " ", 1);
		tools->width--;
		toolsone->retlen++;
	}
}

void	width_and_prec_else_if(t_conv *tools, t_convone *toolsone)
{
	while (tools->width > tools->len)
	{
		write(1, " ", 1);
		tools->width--;
		toolsone->retlen++;
	}
}
