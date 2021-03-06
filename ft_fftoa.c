/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fftoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:27:40 by kbaker            #+#    #+#             */
/*   Updated: 2019/07/13 16:28:55 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	ft_pow2(int nb, int power)
{
	int			cpt;
	long long	value;

	cpt = 1;
	value = nb;
	if (power > 0)
		while (cpt++ < power)
			value = value * nb;
	else
	{
		if (power == 0)
			value = 1;
		else
			value = 0;
	}
	return (value);
}

static long				ft_round(double n, int precision)
{
	long long	tmp;

	tmp = n * ft_pow2(10, precision + 1);
	if (tmp % 10 >= 5)
		tmp = tmp / 10 + 1;
	else if (tmp % 10 <= -5)
		tmp = tmp / 10 - 1;
	else
		tmp /= 10;
	return (tmp);
}

char					*ft_ldtoa(double n, int precision)
{
	char		*str;
	long long	tmp;
	long long	t;
	int			length;

	if (!precision)
		precision = 6;
	tmp = ft_round(n, precision);
	t = (tmp < 0) ? -tmp : tmp;
	length = (n < 0 ? 3 : 2);
	while (tmp /= 10)
		++length;
	(n < 1 && n > -1) ? length = 3 + precision : 0;
	(n >= 0 && n < 1) ? length = 2 + precision : 0;
	if (!(str = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	str[length] = '\0';
	while (length--)
	{
		str[length] = (!precision--) ? '.' : t % 10 + '0';
		t /= (precision + 1) ? 10 : 1;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
