/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_width_zero.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:41:01 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/13 17:07:34 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hash_width_zero_flag(t_conv *tools, t_convone *toolsone)
{
	write(1, "0x", 2);
	RETLEN += 2;
	while (WIDTH > LEN)
	{
		write(1, "0", 1);
		WIDTH--;
		RETLEN++;
	}
	ZERO = 0;
	HASH = 0;
}
