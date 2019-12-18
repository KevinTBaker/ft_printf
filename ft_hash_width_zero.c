/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_width_zero.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:41:01 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/17 16:51:51 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hash_width_zero_flag(t_conv *tools, t_convone *toolsone)
{
	write(1, "0x", 2);
	toolsone->retlen += 2;
	while (tools->width > tools->len)
	{
		write(1, "0", 1);
		tools->width--;
		toolsone->retlen++;
	}
	tools->zero = 0;
	tools->hash = 0;
}
