/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriljade <apriljade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:15:16 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/17 18:04:08 by apriljade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	printed_count;

	printed_count = 0;
	while (*str)
		printed_count += write(1, str++, 1);
	return (printed_count);
}

int	get_hex_digit(unsigned int value)
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

unsigned long long	get_pow_of_16(int digit)
{
	unsigned long long	ret;

	ret = 1;
	while (--digit)
		ret *= 16;
	return (ret);
}