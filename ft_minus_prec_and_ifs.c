/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_prec_and_ifs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:05:40 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/16 19:38:29 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minus_prec_width_space_neg(t_conv *tools, t_convone *toolsone)
{
	if (tools->neg == 1 && tools->prec == 0)
	{
		ft_putchar('-');
		tools->neg = 0;
		tools->len++;
	}
	if (tools->space == 1)
	{
		ft_putchar(' ');
		tools->width--;
		tools->space = 0;
	}
	while (tools->prec > 0)
	{
		if (tools->neg == 1)
		{
			ft_putchar('-');
			tools->neg = 0;
			tools->len++;
		}
		write(1, "0", 1);
		tools->prec--;
		toolsone->retlen++;
	}
}

void	minus_width_hash(t_conv *tools, t_convone *toolsone)
{
	write(1, "0", 1);
	if (tools->lil_x == 1)
	{
		write(1, "x", 1);
		tools->width--;
		toolsone->retlen++;
	}
	else if (tools->big_x == 1)
	{
		write(1, "X", 1);
		tools->width--;
		toolsone->retlen++;
	}
	tools->width--;
	tools->hash = 0;
	toolsone->retlen++;
}

void	if_neg_or_plus(t_conv *tools, t_convone *toolsone)
{
	if (tools->neg == 1)
	{
		toolsone->retlen++;
		tools->width--;
	}
	if (tools->plus == 1)
	{
		tools->width--;
		toolsone->retlen++;
	}
}

void	if_plus_or_neg(t_conv *tools)
{
	if (tools->plus == 1)
	{
		ft_putchar('+');
		tools->plus = 0;
	}
	if (tools->neg == 1)
	{
		ft_putchar('-');
		tools->neg = 0;
	}
	tools->wplus = 1;
}

int		else_if_prec(t_conv *tools, int n, int len)
{
	n = tools->prec;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
