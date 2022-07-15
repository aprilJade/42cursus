/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:35:25 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/15 18:10:06 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include <stdarg.h>

void	init_function_table(void *functions[])
{
	int	i = 0;
	while (i < 128)
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
	va_list ap;
	int		printed_count;
	void	*functions[128];
	int		(*func)(va_list *);

	va_start(ap, s);
	printed_count = 0;
	init_function_table(functions);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			func = functions[(int)*s++];
			if (func == NULL)
				break ;
			printed_count += func(&ap);		
		}
		else
			printed_count += ft_putchar(*s++);
	}
	va_end(ap);
	return (printed_count);
}