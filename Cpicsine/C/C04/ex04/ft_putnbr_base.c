/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:21:12 by seonggyk          #+#    #+#             */
/*   Updated: 2022/05/02 11:25:33 by seonggyk         ###   ########.fr       */
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

void	print_number_in_base(long long n, char *base, int base_len)
{
	if (n >= base_len)
	{
		print_number_in_base(n / base_len, base, base_len);
		write(1, &base[n % base_len], 1);
	}
	else
		write(1, &base[n % base_len], 1);
}

void	ft_putnbr_base(int n, char *base)
{
	long long	ln;

	if (validate_base(base) == FALSE)
		return ;
	ln = (long long)n;
	if (ln < 0)
	{
		write(1, "-", 1);
		ln = -ln;
	}
	print_number_in_base(ln, base, ft_strlen(base));
	return ;
}	
/*
int main(void)
{

	ft_putnbr_base(-47394333, "0123456789abcdef");
}
*/
