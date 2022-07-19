/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:35:35 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/25 11:40:57 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0 || nb > 2147395600)
		return (0);
	i = 0;
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_sqrt(36));
	printf("%d\n", ft_sqrt(2));
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(-36));
	printf("%d\n", ft_sqrt(1640045925));
	printf("%d\n", ft_sqrt(2147395600));
}
*/
