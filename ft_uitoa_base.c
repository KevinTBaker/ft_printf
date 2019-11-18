/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:34:03 by kbaker            #+#    #+#             */
/*   Updated: 2019/07/12 20:34:19 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_size(unsigned long long new, const size_t base)
{
	size_t		size;

	size = 1;
	while (new > base - 1)
	{
		new /= base;
		size++;
	}
	return (size);
}

static void		ft_fill_nbr(char *nbr, long long n, const size_t base, size_t i)
{
	while (i--)
	{
		nbr[i] = (char)(n % base + ((n % base > 9) ? 'A' - 10 : '0'));
		n /= base;
	}
}

char			*ft_uitoa_base2(long long nb, const size_t base)
{
	size_t				i;
	size_t				signe;
	long long			n;
	char				*nbr;

	if (base <= 1)
		return (NULL);
	signe = 0;
	n = nb;
	i = ft_size(n, base);
	if (!(nbr = ft_strnew(i + signe)))
		return (NULL);
	ft_fill_nbr(nbr, n, base, i + signe);
	if (signe == 1)
		nbr[0] = '-';
	return (nbr);
}
