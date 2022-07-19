/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 07:25:35 by nekodev           #+#    #+#             */
/*   Updated: 2022/05/02 19:33:12 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*ret;

	ret = (int *)malloc(sizeof(int) * length);
	if (ret == 0)
		return (0);
	i = 0;
	while (i < length)
	{
		ret[i] = f(tab[i]);
		i++;
	}
	return (ret);
}
/*
int	multi(int n)
{
	return (n * 2);
}

#include <stdio.h>
int main(void)
{
	int arr[5] = {1, 2, 3, 4, 5};
	int *a = ft_map(arr, 5, multi);
	for (int i = 0; i < 5; i++)
		printf("%d\n", arr[i]);
	for (int i = 0; i < 5; i++)
		printf("%d\n", a[i]);
	if (a != 0)
		free(a);
}
*/
