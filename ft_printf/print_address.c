/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriljade <apriljade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:28:22 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/19 19:02:51 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf_utils.h"

int	print_address(va_list *ap)
{
	unsigned char		*value;
	unsigned char		*p_value;
	char				*hex_chars;
	int					printed_count;
	int					i;

	value = va_arg(*ap, unsigned char *);
	if (value == NULL)
		return (ft_putstr("0x0"));
	p_value = (unsigned char *)&value;
	hex_chars = "0123456789abcdef";
	printed_count = 0;
	printed_count = write(1, "0x", 2);
	i = sizeof(size_t) - 1;
	while (p_value[i] == 0)
		i--;
	if (p_value[i] < 16)
		printed_count += ft_putchar(hex_chars[p_value[i--] % 16]);
	while (i >= 0)
	{
		printed_count += ft_putchar(hex_chars[p_value[i] / 16]);
		printed_count += ft_putchar(hex_chars[p_value[i--] % 16]);
	}
	return (printed_count);
}
