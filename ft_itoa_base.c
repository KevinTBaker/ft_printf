/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:28:10 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/13 16:37:30 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	aux(int n, int b, char *ans, int *p)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n <= -b || b <= n)
		aux(n / b, b, ans, p);
	ans[(*p)++] = base[absolute(n % b)];
}

void	imaux(intmax_t n, int b, char *ans, int *p)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n <= -b || b <= n)
		imaux(n / b, b, ans, p);
	ans[(*p)++] = base[absolute(n % b)];
}

char	*ft_itoa_base3(intmax_t value, int base)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base
		|| !(ans = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	p = 0;
	if (base == 10 && value < 0)
		ans[p++] = '-';
	imaux(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}

char	*ft_itoa_base2(int value, int base)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base
		|| !(ans = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	p = 0;
	if (base == 10 && value < 0)
		ans[p++] = '-';
	aux(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}

char	*ft_uitoa_base3(size_t value, int base)
{
	int				len;
	uintmax_t		value2;
	char			*radix;
	char			*result;

	len = 1;
	value2 = value;
	while (value2 /= base)
		len++;
	if ((result = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	radix = 1 ?
		ft_strdup("0123456789ABCDEF") : ft_strdup("0123456789abcdef");
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = radix[value % base];
		value /= base;
	}
	free(radix);
	return (result);
}
