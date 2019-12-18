/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:12:27 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/16 17:08:33 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		parser(char *str, t_conv *tools, t_convone *toolsone, int i)
{
	if (str[i] == '%' && tools->percent == 0)
	{
		tools->percent = 1;
		i++;
	}
	if (tools->percent != 1)
	{
		ft_putchar(str[i]);
		toolsone->retlen++;
	}
	else
	{
		if (str[i] == '%')
		{
			tools->dperc = 1;
			tools->percent = 0;
		}
		i = gather_flags(str, i, tools, toolsone);
		i = gather_prec(str, i, tools);
		i = gather_length(str, i, tools);
		i = gather_convs(str, i, tools);
		i = gather_doubleperc(str, i, tools);
	}
	return (i);
}

void	ft_doing(t_conv *tools, t_convone *toolsone)
{
	if (tools->flag == 1)
		flags_get_done(tools, toolsone);
	if (tools->pw_exist == 1)
		precision_and_width_get_it(tools, toolsone);
}

int		ft_printf(const char *format, ...)
{
	t_conv		tools;
	t_convone	toolsone;
	va_list		vl;
	int			i;

	va_start(vl, format);
	i = 0;
	ft_bzero(&tools, sizeof(t_conv));
	ft_bzero(&toolsone, sizeof(t_convone));
	while (format[i])
	{
		i = parser((char *)format, &tools, &toolsone, i);
		if (tools.convs == 1)
			convs_get_done(&tools, &toolsone, vl);
		else if (tools.dperc == 1)
			toolsone.retlen = double_perc_done(&tools, &toolsone);
		if (format[i] != '\0')
			i++;
	}
	return (toolsone.retlen);
}
