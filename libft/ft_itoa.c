/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:40:26 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/09 17:30:40 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_digit_len(long long n)
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

char	*ft_itoa(int n)
{
	char		*ret;
	long long	ln;
	int			is_negative;
	int			ret_len;

	ln = (long long)n;
	is_negative = ln < 0;
	if (is_negative)
		ln *= -1;
	ret_len = get_digit_len(ln);
	ret = (char *)malloc(sizeof(char) * (ret_len + 1 + is_negative));
	if (ret == NULL)
		return (NULL);
	if (is_negative)
		ret[0] = '-';
	ret[ret_len + is_negative] = 0;
	while (ret_len)
	{
		ret[ret_len-- + is_negative - 1] = (ln % 10) + '0';
		ln /= 10;
	}
	return (ret);
}
