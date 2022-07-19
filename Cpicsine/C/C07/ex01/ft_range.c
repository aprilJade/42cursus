/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:49:11 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/25 11:56:29 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ret;
	int	cnt;
	int	i;

	if (min >= max)
		return (0);
	cnt = max - min;
	ret = (int *)malloc(sizeof(int) * cnt);
	i = 0;
	while (i < cnt)
		ret[i++] = min++;
	return (ret);
}
/*
#include <stdio.h>
int main(void)
{
	int *arr = ft_range(-30, -24);
	for (int i = 0; i < 6; i++)
		printf("%d\n", arr[i]);
	free(arr);
}
*/
