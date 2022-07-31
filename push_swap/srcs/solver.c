/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:47:51 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 13:55:57 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

void	sort(int *data, int size)
{
	int	i;
	int j;
	int	tmp;
	
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (data[i] < data[j])
			{
				tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
			}
			j++;
		}
		i++;
	}
}