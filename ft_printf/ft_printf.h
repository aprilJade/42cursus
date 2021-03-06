/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriljade <apriljade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:24:51 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/18 16:09:07 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

# define SUPPORTED_FORMAT_COUNT 9
# define UNSUPPORTED_FORMAT 0
# define FUNCTION_TABLE_SIZE 256

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
