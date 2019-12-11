/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lengths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 19:29:01 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/10 17:46:38 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_deci_lengths_done(t_conv *tools, va_list vl)
{
	if (DOUBLEH == 1)
		NBR = (signed char)va_arg(vl, int);
	else if (SINGLEH == 1)
		NBR = (short int)va_arg(vl, int);
	else if (SINGLEL == 1)
		NBR = (long int)va_arg(vl, intmax_t);
	else if (DOUBLEL == 1)
		NBR = (long long)va_arg(vl, intmax_t);
	else
		NBR = va_arg(vl, int);
}

void	ft_octals_hex(t_conv *tools, va_list vl)
{
	if (DOUBLEH == 1)
		NBR = (unsigned char)va_arg(vl, uintmax_t);
	else if (SINGLEH == 1)
		NBR = (unsigned short int)va_arg(vl, uintmax_t);
	else if (SINGLEL == 1)
		NBR = va_arg(vl, long);
	else if (DOUBLEL == 1)
		NBR = va_arg(vl, long long);
	else 
		NBR = va_arg(vl, uintmax_t);
}

void	ft_unsigned_len(t_conv *tools, va_list vl)
{
	if (DOUBLEH == 1)
		NBR = (unsigned char)va_arg(vl, unsigned int);
	else if (SINGLEH == 1)
		NBR = (short int)va_arg(vl, uintmax_t);
	else if (SINGLEL == 1)
		NBR = (unsigned long int)va_arg(vl, uintmax_t);
	else if (DOUBLEL == 1)
		NBR = (unsigned long long int)va_arg(vl, uintmax_t);
	else
		NBR = va_arg(vl, unsigned int);
}

void	ft_floats_ls(t_conv *tools, va_list vl)
{
	if (DOUBLEL == 1 && LILF == 1)
		F = (long double)va_arg(vl, double);
	else if (BIGL == 1)
		F = (long double)va_arg(vl, double);
}
