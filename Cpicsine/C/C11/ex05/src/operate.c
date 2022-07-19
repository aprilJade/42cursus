/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:01:32 by seonggyk          #+#    #+#             */
/*   Updated: 2022/05/03 19:34:32 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operate.h"
#include "../includes/atoi.h"
#include "../includes/operator.h"
#include <unistd.h>

void	ft_putnbr(long long n)
{
	char	c;

	if (n < 0)
		n = -n;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		c = (n % 10) + '0';
		write(1, &c, 1);
	}
	else
	{
		c = (n % 10) + '0';
		write(1, &c, 1);
	}
}

int	operate(char *a, char *b, int (*op)(int, int))
{
	int	f;
	int	s;
	int	result;

	f = ft_atoi(a);
	s = ft_atoi(b);
	if (s == 0)
	{
		if ((void *)op == (void *)divide)
		{
			write(1, "Stop : division by zero\n", 24);
			return (-1);
		}
		if ((void *)op == (void *)modular)
		{
			write(1, "Stop : modulo by zero\n", 22);
			return (-1);
		}
	}
	result = op(f, s);
	if (result < 0)
		write(1, "-", 1);
	ft_putnbr((long long)result);
	write(1, "\n", 1);
	return (0);
}
