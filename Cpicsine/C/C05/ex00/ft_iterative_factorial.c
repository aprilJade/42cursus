/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:29:50 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/24 18:04:42 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ret;

	if (nb < 0)
		return (0);
	if (nb < 1)
		return (1);
	ret = 1;
	while (nb > 0)
		ret *= nb--;
	return (ret);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_iterative_factorial(8));
}
*/
