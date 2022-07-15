/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:17:28 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/15 17:18:13 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf_utils.h"

int	print_string(va_list *ap)
{
	char	*s;

	s = va_arg(*ap, char *);
	return (ft_putstr(s));	
}