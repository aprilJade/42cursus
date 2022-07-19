/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriljade <apriljade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:35:25 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/18 10:29:17 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "ft_printf_utils.h"

void	init_function_table(void *functions[])
{
	int	i;

	i = 0;
	while (i < FUNCTION_TABLE_SIZE)
		functions[i++] = NULL;
	functions[CHARACTER] = print_char;
	functions[STRING] = print_string;
	functions[ADDRESS] = print_address;
	functions[DECIMAL_I] = print_decimal;
	functions[DECIMAL_D] = print_decimal;
	functions[UNSIGNED_DECIMAL] = print_unsigned_decimal;
	functions[HEX_LOWERCASE] = print_hex_lower;
	functions[HEX_UPPERCASE] = print_hex_upper;
	functions[PERCENT_SIGN] = print_percent_sign;
}

int	ft_printf(char *s, ...)
{
	va_list	ap;
	int		printed_count;
	void	*functions[FUNCTION_TABLE_SIZE];
	int		(*func)(va_list *);

	va_start(ap, s);
	printed_count = 0;
	init_function_table(functions);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			func = functions[(unsigned int)*s++];
			if (func == UNSUPPORTED_FORMAT)
				break ;
			printed_count += func(&ap);
		}
		else
			printed_count += ft_putchar(*s++);
	}
	va_end(ap);
	return (printed_count);
}
