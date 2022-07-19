/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:11:19 by seonggyk          #+#    #+#             */
/*   Updated: 2022/05/02 09:19:55 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (TRUE);
	return (FALSE);
}

int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (TRUE);
	return (FALSE);
}

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int	ft_atoi(char *str)
{
	long long	result;
	int			sign;

	sign = 1;
	result = 0;
	while (is_space(*str) == TRUE)
		str++;
	if (*str == 0)
		return (result);
	while (is_sign(*str) == TRUE)
	{
		if (*str++ == '-')
			sign = -sign;
	}
	while (is_numeric(*str) == TRUE)
		result = result * 10 + (*str++ - '0');
	return ((int)(result * sign));
}
/*
#include <stdio.h>

int main(void)
{
	printf("%d\n", ft_atoi("   --+--++-1234ab"));
	return (0);
}
*/
