/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:06:03 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/16 08:20:07 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const int	g_int_min = -2147483648;
const char	*g_str_int_min = "-2147483648";

void	ft_strrev(char *str)
{
	int		strlen;
	int		idx;
	char	tmp;

	strlen = 0;
	idx = 0;
	while (str[idx++] != '\0')
		strlen++;
	idx = 0;
	while (idx < strlen / 2)
	{
		tmp = str[idx];
		str[idx] = str[strlen - idx - 1];
		str[strlen - idx - 1] = tmp;
		idx++;
	}
}

void	ft_strcpy(char *dst, char *src)
{
	while (*src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
}

void	ft_int_to_char(int nb, char *buffer, int size)
{
	int		idx;
	int		is_negative;

	if (nb == g_int_min)
	{
		ft_strcpy(buffer, (char *)g_str_int_min);
		return ;
	}
	idx = 0;
	is_negative = 0;
	if (nb < 0)
	{
		nb *= -1;
		is_negative = 1;
	}
	while ((nb / 10) > 0 && idx < size - 1)
	{
		buffer[idx++] = nb % 10 + 48;
		nb /= 10;
	}
	buffer[idx++] = nb + 48;
	if (is_negative == 1)
		buffer[idx++] = '-';
	buffer[idx] = '\0';
	ft_strrev(buffer);
}

void	ft_putnbr(int nb)
{
	char	str_nb[12];
	int		idx;

	idx = 0;
	ft_int_to_char(nb, str_nb, 12);
	while (str_nb[idx] != '\0')
		write(1, &str_nb[idx++], 1);
}
