/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:03:00 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/17 16:24:16 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hash_flag_done(t_conv *tools, t_convone *toolsone)
{
	if (tools->hash == 1 && tools->nbr != 0)
	{
		if (tools->lil_o == 1)
			lilo_hash_width_and_prec(tools, toolsone);
		else if (tools->lil_x == 1)
			lilx_hash_width_prec(tools, toolsone);
		else if (tools->big_x == 1)
			bigx_hash_width_prec(tools, toolsone);
		tools->hash = 0;
		tools->dhash = 1;
	}
}

void	zero_flag_done(t_conv *tools, t_convone *toolsone)
{
	if (tools->neg == 1)
	{
		write(1, "-", 1);
		if (tools->width != 0)
			tools->len++;
		tools->neg = 0;
	}
	if (tools->width != 0)
		tools->width = tools->width - tools->len;
	while (tools->width > 0)
	{
		write(1, "0", 1);
		tools->width--;
		toolsone->retlen++;
	}
	main_width_and_prec(tools, toolsone);
	tools->zero = 0;
	tools->width = 0;
}

void	plus_and_space_flag_done(t_conv *tools, t_convone *toolsone)
{
	if (tools->plus == 1)
		plus_and_space_if_nbr_is_positive(tools, toolsone);
	else if (tools->space == 1 && tools->dperc == 0)
		space_if_nbr_is_positive(tools, toolsone);
	tools->percent = 0;
}

void	minus_flag_done(t_conv *tools, t_convone *toolsone)
{
	if (tools->width != 0)
		toolsone->unbr = 1;
	else
		main_width_and_prec(tools, toolsone);
}

void	flags_get_done(t_conv *tools, t_convone *toolsone)
{
	if ((tools->prec != 0 && tools->width != 0) && (tools->zero == 1))
		tools->zero = 0;
	if (tools->hash == 1)
		hash_flag_done(tools, toolsone);
	else if (tools->plus == 1)
		plus_and_space_flag_done(tools, toolsone);
	else if (tools->space == 1)
		plus_and_space_flag_done(tools, toolsone);
	if (tools->zero == 1)
		zero_flag_done(tools, toolsone);
	else if (tools->minus == 1)
		minus_flag_done(tools, toolsone);
}
