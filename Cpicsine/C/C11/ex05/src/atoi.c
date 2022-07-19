/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 08:56:14 by seonggyk          #+#    #+#             */
/*   Updated: 2022/05/02 08:56:47 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/atoi.h"

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(char *str_num)
{
	int	sign;
	int	ret;

	sign = 1;
	ret = 0;
	while (is_whitespace(*str_num))
		str_num++;
	if (*str_num == 0)
		return (0);
	while (is_sign(*str_num))
	{
		if (*str_num == '-')
			sign = -sign;
		str_num++;
	}
	while (is_number(*str_num) && *str_num)
		ret = ret * 10 + (*str_num++ - '0');
	return (ret * sign);
}
