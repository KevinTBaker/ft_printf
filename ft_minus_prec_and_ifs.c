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
	if (NEG == 1 && PREC == 0)
	{
		ft_putchar('-');
		NEG = 0;
		LEN++;
	}
	if (SPACE == 1)
	{
		ft_putchar(' ');
		WIDTH--;
		SPACE = 0;
	}
	while (PREC > 0)
	{
		if (NEG == 1)
		{
			ft_putchar('-');
			NEG = 0;
			LEN++;
		}
		write(1, "0", 1);
		PREC--;
		RETLEN++;
	}
}

void	minus_width_hash(t_conv *tools, t_convone *toolsone)
{
	write(1, "0", 1);
	if (LILX == 1)
	{
		write(1, "x", 1);
		WIDTH--;
		RETLEN++;
	}
	else if (BIGX == 1)
	{
		write(1, "X", 1);
		WIDTH--;
		RETLEN++;
	}
	WIDTH--;
	HASH = 0;
	RETLEN++;
}

void	if_neg_or_plus(t_conv *tools, t_convone *toolsone)
{
	if (NEG == 1)
	{
		RETLEN++;
		WIDTH--;
	}
	if (PLUS == 1)
	{
		WIDTH--;
		RETLEN++;
	}
}

void	if_plus_or_neg(t_conv *tools)
{
	if (PLUS == 1)
	{
		ft_putchar('+');
		PLUS = 0;
	}
	if (NEG == 1)
	{
		ft_putchar('-');
		NEG = 0;
	}
	WPLUS = 1;
}

int		else_if_prec(t_conv *tools, int n, int len)
{
	n = PREC;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
