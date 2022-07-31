/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:16:37 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 16:45:05 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parser.h"
#include "string_utils.h"
#include <stdlib.h>
#include "err.h"

static int	count_tab(char **tab)
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

static void	from_tab(char ***tab, int cnt, t_element **out)
{
	t_element	*ret;
	int			i;
	char		**tmp;
	int			tmp_ret;

	ret = (t_element *)malloc(sizeof(t_element) * cnt);
	if (ret == NULL)
		print_with_exit(MALLOC_ERR);
	i = 0;
	while (*tab)
	{
		tmp = *tab;
		while (*tmp)
		{
			if (!ft_atoi(*tmp++, &tmp_ret))
				print_with_exit(INVALID_INPUT_ERR);
			ret[i].value = tmp_ret;
			i++;
		}
		tab++;
	}
	*out = ret;
}

int	parse_argv(int ac, char **av, t_element **out)
{
	char		***tmp;
	int			cnt;
	int			i;

	tmp = (char ***)malloc(sizeof(char **) * (ac));
	if (tmp == NULL)
		exit(1);
	tmp[ac - 1] = NULL;
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
	from_tab(tmp, cnt, out);
	return (cnt);
}
