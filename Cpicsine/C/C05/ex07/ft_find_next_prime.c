/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:36:57 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/25 14:29:02 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int n)
{
	int	i;

	i = 2;
	while (i <= n / i)
	{
		if (n % i++ == 0)
			return (0);
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb < 3)
		return (2);
	i = nb;
	while (is_prime(i) == 0)
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("%d\n", ft_find_next_prime(atoi(argv[1])));
}
*/
