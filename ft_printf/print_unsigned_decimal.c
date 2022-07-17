/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriljade <apriljade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:23:00 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/17 18:27:12 by apriljade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf_utils.h"

static int	get_digit_len(unsigned long long n)
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

static char	*ft_utoa(unsigned int n)
{
	char				*ret;
	unsigned long long	ln;
	int					ret_len;

	ln = (unsigned long long)n;
	ret_len = get_digit_len(ln);
	ret = (char *)malloc(sizeof(char) * (ret_len + 1));
	if (ret == NULL)
		return (NULL);
	ret[ret_len] = 0;
	while (ret_len)
	{
		ret[ret_len-- - 1] = (ln % 10) + '0';
		ln /= 10;
	}
	return (ret);
}

int print_unsigned_decimal(va_list *ap)
{
	unsigned int	value;
	char			*svalue;
	int				printed_count;

	value = va_arg(*ap, unsigned int);
	svalue = ft_utoa(value);
	if (svalue == NULL)
		return (0);
	printed_count = ft_putstr(svalue);
	free(svalue);
	return (printed_count);
}