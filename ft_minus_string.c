/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:07:14 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/17 20:01:30 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minus_string_p_and_w(char *s1, char *s2,
		t_conv *tools, t_convone *toolsone)
{
	if ((tools->minus == 1) && (tools->prec != 0 && tools->width != 0))
	{
		if (tools->prec < tools->len)
			tools->len = tools->prec;
		tools->width = tools->width - tools->len;
		tools->prec = 0;
		tools->mnbr = 1;
		toolsone->unbr = 1;
		s2 = ft_memalloc(tools->len + 1);
		ft_strncpy(s2, s1, tools->len);
		s2[tools->len + 1] = '\0';
		if (tools->periprec != 1)
			ft_putstr(s2);
		if (tools->zlen == 1)
			tools->len = 0;
		tools->minus = 0;
	}
	if (tools->width != 0)
		ft_minus_string_w(s1, tools, toolsone);
}

void	ft_minus_string_w(char *s1, t_conv *tools, t_convone *toolsone)
{
	if (toolsone->unbr != 1 || tools->mnbr != 1)
	{
		if (tools->periprec != 1)
			ft_putstr(s1);
		toolsone->unbr = 1;
		tools->mnbr = 1;
		tools->width = tools->width - tools->len;
	}
	while (tools->width > 0)
	{
		write(1, " ", 1);
		tools->width--;
		toolsone->retlen++;
	}
	tools->width = 0;
}
