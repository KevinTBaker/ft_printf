/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_convs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:12:03 by kbaker            #+#    #+#             */
/*   Updated: 2019/07/12 20:48:23 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		gather_strings_character(char *str, int i, t_conv *tools)
{
	if (LILS == 0)
	{
		if (str[i] == 's')
			LILS = 1;
	}
	if (LILC == 0)
	{
		if (str[i] == 'c')
			LILC = 1;
	}
	return (i);
}

int		gather_pointers_hexes(char *str, int i, t_conv *tools)
{
	if (LILP == 0)
	{
		if (str[i] == 'p')
			LILP = 1;
	}
	if (LILX == 0)
	{
		if (str[i] == 'x')
			LILX = 1;
	}
	if (BIGX == 0)
	{
		if (str[i] == 'X')
			BIGX = 1;
	}
	return (i);
}

int		gather_unsigned_octal_floats(char *str, int i, t_conv *tools)
{
	if (LILU == 0)
	{
		if (str[i] == 'u')
			LILU = 1;
	}
	if (LILO == 0)
	{
		if (str[i] == 'o')
			LILO = 1;
	}
	if (LILF == 0)
	{
		if (str[i] == 'f')
			LILF = 1;
	}
	return (i);
}

int		gather_decimals_integers(char *str, int i, t_conv *tools)
{
	if (LILD == 0)
	{
		if (str[i] == 'd')
			LILD = 1;
	}
	if (LILI == 0)
	{
		if (str[i] == 'i')
			LILI = 1;
	}
	if (LILS == 1 || LILC == 1 || LILP == 1 || LILX == 1 ||
			BIGX == 1 || LILU == 1 || LILO == 1 || LILF == 1
			|| LILD == 1 || LILI == 1)
		CONVS = 1;
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
