/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_and_width2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:16:10 by kbaker            #+#    #+#             */
/*   Updated: 2019/07/13 20:43:26 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ints_width_and_precision2(t_conv *tools, t_convone *toolsone)
{
	if (PLUS == 1)
		ft_putchar('+');
	if ((SPACE == 1) && (WIDTH < PREC))
	{
		ft_putchar(' ');
		RETLEN++;
	}
	//if (UNBR != 1)
	WIDTH = 0;
	PREC = PREC - LEN;
	while (PREC > 0)
	{
		write(1, "0", 1);
		PREC--;
		RETLEN++;
	}
	PREC = 0;
}

void	ints_prec(t_conv *tools, t_convone *toolsone)
{
	if (NEG == 1)
	{
		write(1, "-", 1);
		NEG = 0;
		RETLEN++;
	}
	PREC = PREC - LEN;
	while (PREC > 0)
	{
		write(1, "0", 1);
		PREC--;
		RETLEN++;
	}
}

void	char_width(t_conv *tools, t_convone *toolsone)
{
	if (WIDTH)
	{
		WIDTH = WIDTH - LEN;
		while (WIDTH > 0)
		{
			write(1, " ", 1);
			WIDTH--;
			RETLEN++;
		}
		WIDTH = 0;
	}
}
