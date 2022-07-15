/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:28:22 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/15 17:42:59 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"
#include <stdarg.h>

int	print_address(va_list *ap)
{
	unsigned char	*handle;
	int				i;
	char			*hex_chars;
	int				printed_count;

	handle = va_arg(*ap, unsigned char *);
	i = 8;
	hex_chars = "0123456789abcdef";
	printed_count = write(1, "0x", 2);
	while (i--)
	{
		printed_count += ft_putchar(hex_chars[handle[i] / 16]);
		printed_count += ft_putchar(hex_chars[handle[i] % 16]);
	}
	return (printed_count);
}