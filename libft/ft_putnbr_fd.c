/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:38:02 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/09 17:40:34 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	get_digit_len(long long n)
{
	int	ret;

	if (n == 0)
		return (1);
	ret = 0;
	while (n > 0)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

static int	get_pow_of_10(int n)
{
	int	ret;

	ret = 1;
	while (n--)
		ret *= 10;
	return (ret);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	ln;
	int			is_neg;
	int			digit;
	char		num;

	ln = (long long)n;
	is_neg = ln < 0;
	if (is_neg)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	digit = get_digit_len(ln);
	while (digit--)
	{
		num = ln / get_pow_of_10(digit) + '0';
		write(fd, &num, 1);
		ln %= get_pow_of_10(digit);
	}
}
