/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:37:02 by seonggyk          #+#    #+#             */
/*   Updated: 2022/05/03 10:49:17 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define TRUE 1
#define FALSE 0

int	ft_strlen(char *str)
{
	char	*s;

	s = str;
	while (*str)
		str++;
	return (str - s);
}

int	is_overlap(char b, char *base)
{
	while (*++base)
	{
		if (b == *base)
			return (TRUE);
	}
	return (FALSE);
}

int	validate_base(char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (FALSE);
	while (*base)
	{
		if (*base == '-' || *base == '+')
			return (FALSE);
		if (is_overlap(*base, base) == TRUE)
			return (FALSE);
		if ((*base >= 9 && *base <= 13) || *base == 32)
			return (FALSE);
		base++;
	}
	return (TRUE);
}

int	is_in_base(char c, char *base)
{
	int	idx;

	idx = 0;
	while (base[idx])
	{
		if (c == base[idx])
			return (idx);
		idx++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int			sign;
	long long	result;
	int			base_len;

	sign = 1;
	result = 0;
	if (validate_base(base) == FALSE)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 0)
		return (0);
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -sign;
	if (*str == 0)
		return (0);
	base_len = ft_strlen(base);
	while (is_in_base(*str, base) != -1)
		result = result * base_len + is_in_base(*str++, base);
	return ((int)(result * sign));
}
/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_atoi_base("ffabccd", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("	ffabccd", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("	-ffabccd", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("	-ffabccd", "01234567+89abcdef"));
	printf("%d\n", ft_atoi_base("	-ffabccd", " 0123456789abcdef"));
	printf("%d\n", ft_atoi_base("	-ffabccd", "0123456789abcde"));
	printf("%d\n", ft_atoi_base("a101", "zl"));
}
*/
