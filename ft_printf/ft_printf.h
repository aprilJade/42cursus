/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:24:51 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/15 17:49:18 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>

#define SUPPORTED_FORMAT_COUNT 9

int	print_char(va_list *ap);
int	print_string(va_list *ap);
int	print_address(va_list *ap);
int	print_decimal(va_list *ap);
int	print_unsigned_decimal(va_list *ap);
int	print_hex_lower(va_list *ap);
int	print_hex_upper(va_list *ap);
int	print_percent_sign(va_list *ap);
int	ft_printf(char *str, ...);

enum e_print_functions
{
	CHARACTER = 'c',
	STRING = 's',
	ADDRESS = 'p',
	DECIMAL_I = 'i',
	DECIMAL_D = 'd',
	UNSIGNED_DECIMAL = 'u',
	HEX_LOWERCASE = 'x',
	HEX_UPPERCASE = 'X',
	PERCENT_SIGN = '%'
};

#endif