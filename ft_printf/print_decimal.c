/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriljade <apriljade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:18:41 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/17 18:27:03 by apriljade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf_utils.h"

int	get_digit_len(long long n)
{
	int	ret;

	if (n == 0)
		return (1);
	ret = 0;
	while (n > 0)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char		*ret;
	long long	ln;
	int			is_negative;
	int			ret_len;

	ln = (long long)n;
	is_negative = ln < 0;
	if (is_negative)
		ln *= -1;
	ret_len = get_digit_len(ln);
	ret = (char *)malloc(sizeof(char) * (ret_len + 1 + is_negative));
	if (ret == NULL)
		return (NULL);
	if (is_negative)
		ret[0] = '-';
	ret[ret_len + is_negative] = 0;
	while (ret_len)
	{
		ret[ret_len-- + is_negative - 1] = (ln % 10) + '0';
		ln /= 10;
	}
	return (ret);
}

int print_decimal(va_list *ap)
{
	int		value;
	char	*svalue;
	int		printed_count;

	value = va_arg(*ap, int);
	svalue = ft_itoa(value);
	if (svalue == NULL)
		return (0);
	printed_count = ft_putstr(svalue);
	free(svalue);
	return (printed_count);
}