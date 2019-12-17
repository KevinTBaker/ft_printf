/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_of_pw2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:18:35 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/16 20:03:51 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_len_of_pw_w(int n, int len, t_conv *tools)
{
	n = WIDTH;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
}

void	width_and_prec_if(t_conv *tools, t_convone *toolsone)
{
	if (LEN == 0 && PREC > LEN)
	{
		LEN = PREC;
		PREC = 0;
	}
	if (PREC == WIDTH)
	{
		while (PREC > LEN)
		{
			write(1, " ", 1);
			PREC--;
		}
		WIDTH = 0;
	}
	while (WIDTH > PREC)
	{
		write(1, " ", 1);
		WIDTH--;
		RETLEN++;
	}
}

void	width_and_prec_else_if(t_conv *tools, t_convone *toolsone)
{
	while (WIDTH > LEN)
	{
		write(1, " ", 1);
		WIDTH--;
		RETLEN++;
	}
}
