/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:07:14 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/16 16:41:00 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minus_string_p_and_w(char *s1, char *s2,
		t_conv *tools, t_convone *toolsone)
{
	if ((MINUS == 1) && (PREC != 0 && WIDTH != 0))
	{
		if (PREC < LEN)
			LEN = PREC;
		WIDTH = WIDTH - LEN;
		PREC = 0;
		MNBR = 1;
		UNBR = 1;
		s2 = ft_memalloc(LEN + 1);
		ft_strncpy(s2, s1, LEN);
		s2[LEN + 1] = '\0';
		if (PERIPREC != 1)
			ft_putstr(s2);
		if (ZLEN == 1)
			LEN = 0;
		MINUS = 0;
	}
	if (WIDTH != 0)
		ft_minus_string_w(s1, tools, toolsone);
}

void	ft_minus_string_w(char *s1, t_conv *tools, t_convone *toolsone)
{
	if (UNBR != 1 || MNBR != 1)
	{
		if (PERIPREC != 1)
			ft_putstr(s1);
		UNBR = 1;
		MNBR = 1;
		WIDTH = WIDTH - LEN;
	}
	while (WIDTH > 0)
	{
		write(1, " ", 1);
		WIDTH--;
		RETLEN++;
	}
	WIDTH = 0;
}
