/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:17:28 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/18 12:35:15 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf_utils.h"

int	print_string(va_list *ap)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (s == NULL)
		return (ft_putstr("(null)"));
	return (ft_putstr(s));
}
