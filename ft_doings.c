/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:47:06 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/12 16:53:59 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convs_get_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	if (LILD == 1 || LILI == 1)
		RETLEN = integers_done(tools, toolsone, vl);
	else if (LILO == 1)
		RETLEN = octal_done(tools, toolsone, vl);
	else if (LILS == 1)
		RETLEN = strings_done(tools, toolsone, vl);
	else if (LILC == 1)
		RETLEN = chars_done(tools, toolsone, vl);
	else if (LILU == 1)
		RETLEN = unsigned_done(tools, toolsone, vl);
	else if (BIGX == 1)
		RETLEN = uppercase_hex_done(tools, toolsone, vl);
	else if (LILP == 1)
		RETLEN = pointers_done(tools, toolsone, vl);
	else if (LILX == 1)
		RETLEN = lowercase_hex_done(tools, toolsone, vl);
	else if (LILF == 1)
		RETLEN = floats_done(tools, toolsone, vl);
	return (RETLEN);
}
