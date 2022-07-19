/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:56:58 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/25 12:20:43 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int	**range, int min, int max)
{
	int	cnt;
	int	*arr;
	int	i;

	if (min >= max)
		return (0);
	cnt = max - min;
	arr = (int *)malloc(sizeof(int) * cnt);
	i = 0;
	while (i < cnt)
		arr[i++] = min++;
	*range = arr;
	return (cnt);
}
/*
#include <stdio.h>
int main(void)
{
	int *range; 
	ft_ultimate_range(&range, 0, 5);
	for (int i = 0; i < 5; i++)
		printf("%d\n", range[i]);
	free(range);
}
*/
