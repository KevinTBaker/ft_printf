/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searching.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:06:50 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/16 17:12:02 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_search(char c)
{
	if (c == '#' || c == ' ' || c == '0' || c == '+' || c == '-')
		return (1);
	else
		return (0);
}

void	plus_and_space_if_nbr_is_positive(t_conv *tools, t_convone *toolsone)
{
	if (tools->nbr >= 0 && tools->neg == 0)
	{
		if ((tools->prec && !tools->width) || (!tools->prec && !tools->width))
		{
			ft_putchar('+');
			toolsone->retlen++;
		}
		else if (tools->zero == 1)
		{
			ft_putchar('+');
			tools->width--;
			toolsone->retlen++;
			zero_flag_done(tools, toolsone);
		}
		main_width_and_prec(tools, toolsone);
	}
	tools->plus = 0;
}

void	space_if_nbr_is_positive(t_conv *tools, t_convone *toolsone)
{
	if ((tools->nbr >= 0 && toolsone->unbr == 0) && tools->neg == 0)
	{
		if (tools->prec && !tools->width)
		{
			ft_putchar(' ');
			toolsone->retlen++;
		}
		if (!tools->prec && !tools->width)
		{
			ft_putchar(' ');
			toolsone->retlen++;
		}
		if (!tools->prec && tools->width)
		{
			ft_putchar(' ');
			tools->width--;
			toolsone->retlen++;
		}
		main_width_and_prec(tools, toolsone);
	}
	tools->space = 0;
}

void	ft_nbr_and_prec_is_zero(char *s1, t_conv *tools, t_convone *toolsone)
{
	s1 = ft_strnew(1);
	s1 = "0";
	tools->prec = 0;
	tools->len = ft_strlen(s1);
	if (tools->periprec == 1)
		tools->len = tools->prec;
	if (tools->width != 0)
		ints_prec_or_width(tools, toolsone);
	if (tools->periprec != 1)
		ft_putstr(s1);
}

void	ft_nbr_and_prec_else(char *s1, t_conv *tools, t_convone *toolsone)
{
	tools->len = ft_strlen(s1);
	if ((tools->prec == 0 && tools->nbr == 0) && tools->pw_exist == 1)
	{
		s1 = ft_strnew(1);
		s1 = "0";
		tools->prec = 0;
		tools->len = ft_strlen(s1);
		if (tools->periprec == 1)
		{
			toolsone->unbr = 1;
			if (tools->plus == 1 && tools->minus == 1)
			{
				tools->plus = 0;
				ft_putchar('+');
				tools->width--;
			}
			tools->len = tools->prec;
			tools->minus = 0;
		}
	}
	if (tools->minus == 1 && tools->periprec == 0)
		ft_minus_and_plus(s1, tools, toolsone);
	ft_doing(tools, toolsone);
	if (toolsone->unbr != 1)
		ft_putstr(s1);
}
