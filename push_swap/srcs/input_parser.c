/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:16:37 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 12:36:22 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parser.h"
#include "string_utils.h"
#include <stdlib.h>
#include "err.h"

int	count_tab(char **tab)
{
	int	cnt;

	cnt = 0;
	while (*tab)
	{
		tab++;
		cnt++;
	}
	return (cnt);
}

int	parse_argv(int ac, char **av, int **out)
{
	char	***tmp;
	int		*ret;
	char	**temp;
	int		cnt;
	int		i;

	tmp = (char ***)malloc(sizeof(char **) * ac);
	if (tmp == NULL)
		exit(1);
	tmp[ac] = NULL;
	av++;
	cnt = 0;
	i = 0;
	while (*av)
	{
		tmp[i] = ft_split(*av++, ' ');
		if (tmp[i] == NULL)
			print_with_exit(SPLIT_ERR);
		cnt += count_tab(tmp[i++]);
	}
	ret = (int *)malloc(sizeof(int) * cnt);
	if (ret == NULL)
		print_with_exit(MALLOC_ERR);
	i = 0;
	while (*tmp)
	{
		temp = *tmp;
		while (*temp)
		{
			if (!ft_atoi(*temp, &ret[i]))
				print_with_exit(INVALID_INPUT_ERR);
			temp++;
			i++;
		}
		tmp++;
	}
	*out = ret;
	return (cnt);
}