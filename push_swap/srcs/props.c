/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   props.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:17:02 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 17:00:28 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "props.h"
#include "input_parser.h"
#include "err.h"
#include <stdlib.h>

static void	copy_elem_arr(int **dst, t_element *src, int cnt)
{
	int	*ret;
	int	i;
	
	ret = (int *)malloc(sizeof(int) * cnt);
	if (ret == 0)
		print_with_exit(MALLOC_ERR);
	i = 0;
	while (i < cnt)
	{
		ret[i] = src[i].value;
		i++;
	}
	*dst = ret;
}

static void	indexing(t_props *props, int data_cnt)
{
	int	i;
	int j;

	i = 0;
	while (i < data_cnt)
	{
		j = 0;
		while (j < data_cnt)
		{
			if (props->a->data[i].value == props->sorted_data[j])
				props->a->data[i].ranking = j;
			j++;
		}
		i++;
	}
}

static void	bubble_sort(int *data, int size)
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

static int	check_duplication(int *data, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt - 1)
	{
		if (data[i] <= data[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	init_props(t_props *props, int ac, char **av)
{
	t_element	*data;
	int			data_cnt;

	data_cnt = parse_argv(ac, av, &data);
	props->a = new_stack(data, data_cnt);
	props->b = new_stack(0, data_cnt);
	copy_elem_arr(&props->sorted_data, props->a->data, data_cnt);
	bubble_sort(props->sorted_data, data_cnt);
	if (check_duplication(props->sorted_data, data_cnt))
		print_with_exit(INVALID_INPUT_ERR);
	indexing(props, data_cnt);
}
