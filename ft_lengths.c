/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lengths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 19:29:01 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/17 17:08:19 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_deci_lengths_done(t_conv *tools, va_list vl)
{
	if (tools->double_h == 1)
		tools->nbr = (signed char)va_arg(vl, int);
	else if (tools->single_h == 1)
		tools->nbr = (short int)va_arg(vl, int);
	else if (tools->single_l == 1)
		tools->nbr = (long int)va_arg(vl, intmax_t);
	else if (tools->double_l == 1)
		tools->nbr = (long long)va_arg(vl, intmax_t);
	else
		tools->nbr = va_arg(vl, int);
}

void	ft_octals_hex(t_conv *tools, va_list vl)
{
	if (tools->double_h == 1)
		tools->nbr = (unsigned char)va_arg(vl, uintmax_t);
	else if (tools->single_h == 1)
		tools->nbr = (unsigned short int)va_arg(vl, uintmax_t);
	else if (tools->single_l == 1)
		tools->nbr = va_arg(vl, long);
	else if (tools->double_l == 1)
		tools->nbr = va_arg(vl, long long);
	else
		tools->nbr = va_arg(vl, unsigned int);
}

void	ft_unsigned_len(t_conv *tools, va_list vl)
{
	if (tools->double_h == 1)
		tools->nbr = (unsigned char)va_arg(vl, unsigned int);
	else if (tools->single_h == 1)
		tools->nbr = (short int)va_arg(vl, uintmax_t);
	else if (tools->single_l == 1)
		tools->nbr = (unsigned long int)va_arg(vl, uintmax_t);
	else if (tools->double_l == 1)
		tools->nbr = (unsigned long long int)va_arg(vl, uintmax_t);
	else
		tools->nbr = va_arg(vl, unsigned int);
}

void	ft_floats_ls(t_conv *tools, va_list vl)
{
	if (tools->double_l == 1 && tools->lil_f == 1)
		tools->flnbr = (long double)va_arg(vl, double);
	else if (tools->big_l == 1)
		tools->flnbr = (long double)va_arg(vl, double);
}
