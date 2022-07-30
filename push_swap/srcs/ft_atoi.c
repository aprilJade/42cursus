/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriljade <apriljade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:01:14 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/30 16:23:31 by apriljade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"

static int	is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str, int *out)
{
	long long	flag;
	long long	n;

	flag = 1;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (!is_numeric(*str))
		return (0);
	n = 0;
	while (is_numeric(*str))
		n = n * 10 + (*str++ - '0');
	if ((n * flag > INT_MAX) || (n * flag < INT_MIN))
		return (0);
	*out = (int)(n * flag);
	return (1);
}
