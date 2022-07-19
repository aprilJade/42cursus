/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 07:19:05 by nekodev           #+#    #+#             */
/*   Updated: 2022/05/01 14:26:43 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
		f(tab[i++]);
}
/*
#include <stdio.h>
void	ft_putnbr(int n)
{
	printf("%d\n", n);
}

int main(void)
{
	int arr[5] = {2, 4, 6, 8, 10};
	ft_foreach(arr, 5, ft_putnbr);
	for (int i = 0; i < 5; i++)
		printf("%d\n", arr[i]);
	return (0);
}
*/
