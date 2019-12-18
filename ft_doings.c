/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:47:06 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/17 16:12:42 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convs_get_done(t_conv *tools, t_convone *toolsone, va_list vl)
{
	if (tools->lil_d == 1 || tools->lil_i == 1)
		toolsone->retlen = integers_done(tools, toolsone, vl);
	else if (tools->lil_o == 1)
		toolsone->retlen = octal_done(tools, toolsone, vl);
	else if (tools->lil_s == 1)
		toolsone->retlen = strings_done(tools, toolsone, vl);
	else if (tools->lil_c == 1)
		toolsone->retlen = chars_done(tools, toolsone, vl);
	else if (tools->lil_u == 1)
		toolsone->retlen = unsigned_done(tools, toolsone, vl);
	else if (tools->big_x == 1)
		toolsone->retlen = uppercase_hex_done(tools, toolsone, vl);
	else if (tools->lil_p == 1)
		toolsone->retlen = pointers_done(tools, toolsone, vl);
	else if (tools->lil_x == 1)
		toolsone->retlen = lowercase_hex_done(tools, toolsone, vl);
	else if (tools->lil_f == 1)
		toolsone->retlen = floats_done(tools, toolsone, vl);
	return (toolsone->retlen);
}
