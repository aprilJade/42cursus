#include "argv_parser.h"
#include "string_utils.h"
#include <stdlib.h>

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
			exit(1);
		cnt += count_tab(tmp[i++]);
	}
	ret = (int *)malloc(sizeof(int) * cnt);
	if (ret == NULL)
		exit(1);
	i = 0;
	while (*tmp)
	{
		temp = *tmp;
		while (*temp)
		{
			if (!ft_atoi(*temp, &ret[i]))
				exit(1);
			temp++;
			i++;
		}
		tmp++;
	}
	*out = ret;
	return (cnt);
}