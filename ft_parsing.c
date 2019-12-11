/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:27:12 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/08 15:34:58 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		gather_flags(char *str, int i, t_conv *tools, t_convone *toolsone)
{
	while (str[i] && FLAGS(str[i]))
	{
		if (!HASH && str[i] == '#')
			HASH = 1;
		else if (!PLUS && str[i] == '+')
			PLUS = 1;
		else if (!SPACE && str[i] == ' ')
			SPACE = 1;
		else if (!ZERO && str[i] == '0' && !MINUS)
			ZERO = 1;
		else if (!MINUS && str[i] == '-')
			MINUS = 1;
		i++;
	}
	if (HASH == 1 || PLUS == 1 || SPACE == 1 || ZERO == 1 || MINUS == 1)
		FLAG = 1;
	if (MINUS == 0)
		UNBR = 0;
	if (SPACE == 1 && PLUS == 1)
		SPACE = 0;
	return (i);
}

int		gather_width1(char *str, int i, t_conv *tools)
{
	/*
	WIDTH = ft_atoi(&str[i]);
	i++;
	if (str[i] == '.')
	{
		i++;
		if (ft_isdigit(str[i + 1]))
		{
			PREC = ft_atoi(&str[i]);
			//i = ft_len_of_pw(str, i, tools);
		}
		//PW_EXIST = 1;
		else
		{
			PREC = 0;
			PW_EXIST = 1;
			PERIPREC = 1;
		}
		//if (str[i] != '.')
		i = ft_len_of_pw(str,i, tools);
		//else
		//	i++;
	}
	return (i);
	*/
	WIDTH = ft_atoi(&str[i]);
	if (str[i + 1] && str[i + 1] == '.')
	{
		if (ft_isdigit(str[i + 2]))
			PREC = ft_atoi(&str[i + 2]);
		else
		{
			PERIPREC = 1;
			PREC = 0;
		}
		if (PREC == 0)
			PERIPREC = 1;
		i += 2;
		//takeout PERIPREC
		/*
		if (ft_isdigit(str[i]))
			PREC = ft_atoi(&str[i]);
		*/
		/*
		else
		{
			PREC = 0;
			PERIPREC = 1;
		}
		*/
	}
	i = ft_len_of_pw(str, i, tools);
	return (i);
}

int		gather_prec2(char *str, int i, t_conv *tools)
{
	PREC = 1;
	i++;
	if (ft_isdigit(str[i]))
	{
		PREC = ft_atoi(&str[i]);
		i = ft_len_of_pw(str, i, tools);
		if (ft_isdigit(str[i]))
		{
			PREC = ft_atoi(&str[i]);
			i = ft_len_of_pw(str, i, tools);
		}
		//takeout if statement
		if (PREC == 0)
			PERIPREC = 1;
		PW_EXIST = 1;
	}
	else
	{
		PREC = 0;
		PW_EXIST = 1;
		PERIPREC = 1;
	}
	return (i);
}

int		gather_prec(char *str, int i, t_conv *tools)
{
	if (ft_isdigit(str[i]) || str[i] == '.')
	{
		if (ft_isdigit(str[i]))
			i = gather_width1(str, i, tools);
		if (str[i] == '.')
			i = gather_prec2(str, i, tools);
	}
	if ((PREC || WIDTH) || (PREC && WIDTH))
		PW_EXIST = 1;
	return (i);
}

int		gather_length(char *str, int i, t_conv *tools)
{
	if (str[i] == 'h' && str[i + 1] == 'h')
		DOUBLEH = 1;
	else if (str[i] == 'h')
		SINGLEH = 1;
	else if (str[i] == 'l' && str[i + 1] == 'l')
		DOUBLEL = 1;
	else if (str[i] == 'l')
		SINGLEL = 1;
	else if (str[i] == 'L')
		BIGL = 1;
	if (DOUBLEH == 1 || SINGLEH == 1 || DOUBLEL == 1 ||
			SINGLEL == 1 || BIGL == 1)
		LENGTHS = 1;
	if (DOUBLEH == 1 || DOUBLEL == 1)
		i += 2;
	else if (SINGLEH == 1 || SINGLEL == 1 || BIGL == 1)
		i += 1;
	return (i);
}
