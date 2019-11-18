/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:28:10 by kbaker            #+#    #+#             */
/*   Updated: 2019/11/15 17:01:56 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define ABS(v) ((v) < 0 ? -(v) : (v))

void	aux(int n, int b, char *ans, int *p)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n <= -b || b <= n)
		aux(n / b, b, ans, p);
	ans[(*p)++] = base[ABS(n % b)];
}

char	*ft_itoa_base(int value, int base)
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

static void	uaux(unsigned int n, unsigned int b, char *ans, int *p)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n <= -b || b <= n)
		aux(n / b, b, ans, p);
	ans[(*p)++] = base[ABS(n % b)];
}
char	*ft_uitoa_base3(unsigned int value, int base)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base
		|| !(ans = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	p = 0;
	uaux(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
/*
char	*ft_uitoa_base3(uintmax_t n, char const *base)
{
	uintmax_t	len;
	uintmax_t	div;
	char		*output;
	uintmax_t	i;
	uintmax_t	base_val;

	base_val = ft_strlen(base);
	div = 1;
	len = 1;
	while (n / div > base_val - 1)
	{
		len++;
		div *= base_val;
	}
	if ((output = ft_strnew(len)) == NULL)
		return (NULL);
	i = 0;
	while (div)
	{
		output[i++] = base[(n / div) % base_val];
		div /= base_val;
	}
	return (output);
}
*/
