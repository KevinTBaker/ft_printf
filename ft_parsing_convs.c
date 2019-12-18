/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_convs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:12:03 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/17 20:02:43 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		gather_strings_character(char *str, int i, t_conv *tools)
{
	if (tools->lil_s == 0)
	{
		if (str[i] == 's')
			tools->lil_s = 1;
	}
	if (tools->lil_c == 0)
	{
		if (str[i] == 'c')
			tools->lil_c = 1;
	}
	return (i);
}

int		gather_pointers_hexes(char *str, int i, t_conv *tools)
{
	if (tools->lil_p == 0)
	{
		if (str[i] == 'p')
			tools->lil_p = 1;
	}
	if (tools->lil_x == 0)
	{
		if (str[i] == 'x')
			tools->lil_x = 1;
	}
	if (tools->big_x == 0)
	{
		if (str[i] == 'X')
			tools->big_x = 1;
	}
	return (i);
}

int		gather_unsigned_octal_floats(char *str, int i, t_conv *tools)
{
	if (tools->lil_u == 0)
	{
		if (str[i] == 'u')
			tools->lil_u = 1;
	}
	if (tools->lil_o == 0)
	{
		if (str[i] == 'o')
			tools->lil_o = 1;
	}
	if (tools->lil_f == 0)
	{
		if (str[i] == 'f')
			tools->lil_f = 1;
	}
	return (i);
}

int		gather_decimals_integers(char *str, int i, t_conv *tools)
{
	if (tools->lil_d == 0)
	{
		if (str[i] == 'd')
			tools->lil_d = 1;
	}
	if (tools->lil_i == 0)
	{
		if (str[i] == 'i')
			tools->lil_i = 1;
	}
	if (tools->lil_s == 1 || tools->lil_c == 1 ||
			tools->lil_p == 1 || tools->lil_x == 1 ||
			tools->big_x == 1 || tools->lil_u == 1 ||
			tools->lil_o == 1 || tools->lil_f == 1
			|| tools->lil_d == 1 || tools->lil_i == 1)
		tools->convs = 1;
	return (i);
}

int		gather_convs(char *str, int i, t_conv *tools)
{
	i = gather_strings_character(str, i, tools);
	i = gather_pointers_hexes(str, i, tools);
	i = gather_unsigned_octal_floats(str, i, tools);
	i = gather_decimals_integers(str, i, tools);
	return (i);
}
