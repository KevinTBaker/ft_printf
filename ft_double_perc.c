/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_perc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:48:56 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/17 16:15:51 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		gather_doubleperc(char *str, int i, t_conv *tools)
{
	if (str[i] == '%')
		tools->dperc = 1;
	tools->percent = 0;
	return (i);
}

int		double_perc_done(t_conv *tools, t_convone *toolsone)
{
	char c;

	c = '%';
	tools->len = 1;
	if (tools->minus == 1)
		ft_putchar(c);
	ft_doing(tools, toolsone);
	if (toolsone->retlen != 0)
		toolsone->retlen = tools->len + toolsone->retlen;
	else
		toolsone->retlen = tools->len;
	if (toolsone->unbr != 1)
		ft_putchar(c);
	ft_bzero(tools, sizeof(t_conv));
	return (toolsone->retlen);
}
