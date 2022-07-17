/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriljade <apriljade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:16:03 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/17 18:04:28 by apriljade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H
#include <unistd.h>

int					ft_putchar(char c);
int					ft_putstr(char *s);
int					get_hex_digit(unsigned int value);
unsigned long long	get_pow_of_16(int digit);

#endif