/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:30:33 by kbaker            #+#    #+#             */
/*   Updated: 2019/07/12 23:34:54 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zeroing_convs(t_conv *tools)
{
	PERC = 0;
	LILD = 0;
	LILP = 0;
	LILI = 0;
	LILD = 0;
	LILO = 0;
	LILU = 0;
	LILX = 0;
	LILF = 0;
	BIGX = 0;
	LILC = 0;
}

int		ft_turn_to_positive(t_conv *tools)
{
	if ((!WIDTH && !PREC) || (MINUS == 1 && PREC == 0))
		return (NBR);
	if (NBR < 0)
		NEG = 1;
	return (NBR * -1);
}

int		ft_len_of_pw(char *str, int i, t_conv *tools)
{
	int		n;
	int		len;

	n = 0;
	len = 0;
	if (WIDTH && !PREC)
	{
		n = WIDTH;
		while (n != 0)
		{
			n = n / 10;
			len++;
		}
	}
	else if (PREC)
	{
		n = PREC;
		while (n != 0)
		{
			n = n / 10;
			len++;
		}
	}
	if (str[i] == '0')
		i++;
	i += len;
	return (i);
}

char	ft_turn_to_lowercase(char *s1)
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
