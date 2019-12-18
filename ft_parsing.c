/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:27:12 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/17 20:03:31 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		gather_flags(char *str, int i, t_conv *tools, t_convone *toolsone)
{
	while (str[i] && flag_search(str[i]))
	{
		if (!tools->hash && str[i] == '#')
			tools->hash = 1;
		else if (!tools->plus && str[i] == '+')
			tools->plus = 1;
		else if (!tools->space && str[i] == ' ')
			tools->space = 1;
		else if (!tools->zero && str[i] == '0' && !tools->minus)
			tools->zero = 1;
		else if (!tools->minus && str[i] == '-')
			tools->minus = 1;
		i++;
	}
	if (tools->hash == 1 || tools->plus == 1 ||
			tools->space == 1 || tools->zero == 1 || tools->minus == 1)
		tools->flag = 1;
	if (tools->minus == 0)
		toolsone->unbr = 0;
	if (tools->space == 1 && tools->plus == 1)
		tools->space = 0;
	return (i);
}

int		gather_width1(char *str, int i, t_conv *tools)
{
	tools->width = ft_atoi(&str[i]);
	if (str[i + 1] && str[i + 1] == '.')
	{
		if (ft_isdigit(str[i + 2]))
			tools->prec = ft_atoi(&str[i + 2]);
		else
		{
			tools->periprec = 1;
			tools->prec = 0;
		}
		if (tools->prec == 0)
			tools->periprec = 1;
		i += 2;
	}
	i = ft_len_of_pw(str, i, tools);
	return (i);
}

int		gather_prec2(char *str, int i, t_conv *tools)
{
	tools->prec = 1;
	i++;
	if (ft_isdigit(str[i]))
	{
		tools->prec = ft_atoi(&str[i]);
		i = ft_len_of_pw(str, i, tools);
		if (ft_isdigit(str[i]))
		{
			tools->prec = ft_atoi(&str[i]);
			i = ft_len_of_pw(str, i, tools);
		}
		if (tools->prec == 0)
			tools->periprec = 1;
		tools->pw_exist = 1;
	}
	else
	{
		tools->prec = 0;
		tools->pw_exist = 1;
		tools->periprec = 1;
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
	if ((tools->prec || tools->width) || (tools->prec && tools->width))
		tools->pw_exist = 1;
	return (i);
}

int		gather_length(char *str, int i, t_conv *tools)
{
	if (str[i] == 'h' && str[i + 1] == 'h')
		tools->double_h = 1;
	else if (str[i] == 'h')
		tools->single_h = 1;
	else if (str[i] == 'l' && str[i + 1] == 'l')
		tools->double_l = 1;
	else if (str[i] == 'l')
		tools->single_l = 1;
	else if (str[i] == 'L')
		tools->big_l = 1;
	if (tools->double_h == 1 || tools->single_h == 1 || tools->double_l == 1 ||
			tools->single_l == 1 || tools->big_l == 1)
		tools->lengths = 1;
	if (tools->double_h == 1 || tools->double_l == 1)
		i += 2;
	else if (tools->single_h == 1 || tools->single_l == 1 || tools->big_l == 1)
		i += 1;
	return (i);
}
