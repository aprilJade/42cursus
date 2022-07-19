/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:50:41 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/16 08:02:33 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar2(char c)
{
	char	first;
	char	second;

	first = (c / 10) + 48;
	second = (c % 10) + 48;
	write(1, &first, 1);
	write(1, &second, 1);
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;

	i = 0;
	while (i < 100)
	{
		j = i + 1;
		while (j < 100)
		{
			ft_putchar2(i);
			write(1, " ", 1);
			ft_putchar2(j);
			if (i != 98)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
