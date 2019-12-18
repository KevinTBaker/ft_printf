/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:30:33 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/17 20:13:50 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		zeroing_convs(t_conv *tools)
{
	tools->percent = 0;
	tools->lil_d = 0;
	tools->lil_p = 0;
	tools->lil_i = 0;
	tools->lil_d = 0;
	tools->lil_o = 0;
	tools->lil_u = 0;
	tools->lil_x = 0;
	tools->lil_f = 0;
	tools->big_x = 0;
	tools->lil_c = 0;
}

intmax_t	ft_turn_to_positive(t_conv *tools)
{
	if (tools->minus == 1 && tools->space == 1)
	{
		if (tools->nbr < 0)
			tools->space = 0;
	}
	if ((!tools->width && !tools->prec) ||
			(tools->minus == 1 && tools->prec == 0))
		return (tools->nbr);
	if (tools->nbr < 0)
		tools->neg = 1;
	return (tools->nbr * -1);
}

int			ft_len_of_pw(char *str, int i, t_conv *tools)
{
	int		n;
	int		len;

	n = 0;
	len = 0;
	if (tools->width && !tools->prec)
	{
		n = tools->width;
		while (n != 0)
		{
			n = n / 10;
			len++;
		}
	}
	else if (tools->prec)
		len = else_if_prec(tools, n, len);
	if (str[i] == '0')
		i++;
	if (ft_isdigit(str[i]))
		i += len;
	return (i);
}

int			absolute(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

char		ft_turn_to_lowercase(char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z')
		{
			s1[i] = s1[i] + 32;
			i++;
		}
		else
			i++;
	}
	return (*s1);
}
