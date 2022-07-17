/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriljade <apriljade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:27:05 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/17 18:30:15 by apriljade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf_utils.h"

int	print_percent_sign(va_list *ap)
{
	va_list	tmp;
	
	va_copy(tmp, *ap);
	return (ft_putchar('%'));
}