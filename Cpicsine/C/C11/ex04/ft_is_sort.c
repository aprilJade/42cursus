/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 07:10:56 by nekodev           #+#    #+#             */
/*   Updated: 2022/05/01 14:27:33 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ascending;
	int	descending;
	int	ret;

	ascending = 0;
	descending = 0;
	i = -1;
	while (++i < length - 1)
	{
		ret = f(tab[i], tab[i + 1]);
		if (ret == 0)
		{
			ascending++;
			descending++;
		}
		else if (ret < 0)
			ascending++;
		else
			descending++;
	}
	if (ascending == i || descending == i)
		return (1);
	else
		return (0);
}
/*
int	argf(int a, int b)
{
	return (a - b);
}
#include <stdio.h>
int main(void)
{
	int arr[4] = {2, 3, 7, 5};
	printf("%d\n", ft_is_sort(arr, 3, argf));
}
*/
