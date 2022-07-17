/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriljade <apriljade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:16:45 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/17 17:47:25 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf_utils.h"

static int	get_hex_digit(unsigned int value)
{
	int	digit;

	if (value == 0)
		return (1);
	digit = 0;
	while (value)
	{
		digit++;
		value /= 16;
	}
	return (digit);
}

static int	get_pow_of_16(int digit)
{
	int	ret;

	ret = 1;
	while (--digit)
		ret *= 16;
	return (ret);
}

int	print_hex_lower(va_list *ap)
{
	unsigned int	value;
	int				hex_digit;
	char			*hex_chars;
	unsigned int	tmp;
	int				printed_count;

	hex_chars = "0123456789abcdef";
	value = va_arg(*ap, unsigned int);
	hex_digit = get_hex_digit(value);
	tmp	= get_pow_of_16(hex_digit);
	printed_count = 0;
	while (hex_digit--)
	{
		printed_count += ft_putchar(hex_chars[(value / tmp) % 16]);
		value %= tmp;
		tmp /= 16;
	}
	return (printed_count);
}

int	print_hex_upper(va_list *ap)
{
	unsigned int	value;
	int				hex_digit;
	char			*hex_chars;
	unsigned int	tmp;
	int				printed_count;

	hex_chars = "0123456789ABCDEF";
	value = va_arg(*ap, unsigned int);
	hex_digit = get_hex_digit(value);
	tmp	= get_pow_of_16(hex_digit);
	printed_count = 0;
	while (hex_digit--)
	{
		printed_count += ft_putchar(hex_chars[(value / tmp) % 16]);
		value %= tmp;
		tmp /= 16;
	}
	return (printed_count);
}
