/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:12:27 by kbaker            #+#    #+#             */
/*   Updated: 2019/11/15 15:44:02 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		parser(char *str, t_conv *tools, t_convone *toolsone, int i)
{
	if (str[i] == '%' && PERC == 0)
	{
		PERC = 1;
		i++;
	}
	if (PERC != 1)
	{
		ft_putchar(str[i]);
		//i++;
		//if (i != 0 && str[i] != '\n')
		RETLEN++;
	}
	else
	{
		if (str[i] == '%')
		{
			D_PERC = 1;
			PERC = 0;
			//RETLEN++;
			i++;
		}
		i = gather_flags(str, i, tools);
		i = gather_prec(str, i, tools);
		i = gather_length(str, i, tools);
		i = gather_convs(str, i, tools);
		i = gather_doubleperc(str, i, tools);
	}
	return (i);
}

void	ft_doing(t_conv *tools, t_convone *toolsone)
{
	if (FLAG == 1)
		flags_get_done(tools, toolsone);
	if (PW_EXIST == 1)
		precision_and_width_get_it(tools, toolsone);
}

int		ft_printf(const char *format, ...)
{
	t_conv		tools;
	t_convone	toolsone;
	va_list		vl;
	int			i;
	//int			nlen;

	//make i in struct so you don't need to pass it all the time
	va_start(vl, format);
	i = 0;
	ft_bzero(&tools, sizeof(t_conv));
	ft_bzero(&toolsone, sizeof(t_convone));
	//if (format[i] == NULL)
	//	return (NULL);
	while (format[i])
	{
		i = parser((char *)format, &tools, &toolsone, i);
		if (tools.convs == 1)
			convs_get_done(&tools, &toolsone,  vl);
		else if (tools.dperc == 1)
			toolsone.retlen = double_perc_done(&tools, &toolsone);
		if (format[i] != '\0')
			i++;
		/*
		if (tools.percent != 1)
		{
			while (format[i] != '\0')
			{
				write(1, &format[i], 1);
				i++;
			}
		}
		*/
	}
	//printf("%d\n", toolsone.retlen);
	return (toolsone.retlen);
}
