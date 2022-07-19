/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:26:09 by seonggyk          #+#    #+#             */
/*   Updated: 2022/05/02 17:25:57 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_strlen(char *str);
int	is_overlap(char b, char *base);
int	validate_base(char *base);

int	get_need_len(long long n, char *base, int sign)
{
	int	result;
	int	blen;

	n *= sign;
	result = 0;
	blen = ft_strlen(base);
	while (n > 0)
	{
		n /= blen;
		result++;
	}
	if (sign == -1)
		result++;
	return (result);
}

int	ft_btoi(char c, char *base)
{
	int	result;

	result = 0;
	while (base[result])
	{
		if (c == base[result++])
			return (result);
	}
	return (result);
}

char	*convert(char *buf, long long n, char *base, int sign)
{
	int		base_len;
	int		i;

	base_len = ft_strlen(base);
	i = get_need_len(n, base, sign);
	n *= sign;
	buf[i--] = 0;
	while (i >= 0)
	{
		buf[i--] = base[n % base_len];
		n /= base_len;
	}
	if (sign == -1)
		buf[0] = '-';
	return (buf);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	ln;
	char		*result;
	int			sign;
	int			need_len;

	sign = 1;
	if (validate_base(base_from) == 0 || validate_base(base_to) == 0)
		return (NULL);
	ln = ft_atoi_base(nbr, base_from);
	if (ln < 0)
		sign = -1;
	need_len = get_need_len(ln, base_to, sign);
	result = (char *)malloc(sizeof(char) * need_len + 1);
	return (convert(result, ln, base_to, sign));
}
