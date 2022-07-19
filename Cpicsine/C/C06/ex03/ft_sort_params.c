/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:41:03 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/26 11:29:12 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	ret;

	ret = 0;
	while (ret == 0)
	{
		ret = *s1 - *s2;
		if (*s1 == 0 || *s2 == 0)
			return (ret);
		s1++;
		s2++;
	}
	return (ret);
}

void	ft_sort(char **strings, int count)
{
	int		i;
	int		j;
	char	*buf;

	i = 1;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_strcmp(strings[i], strings[j]) > 0)
			{
				buf = strings[i];
				strings[i] = strings[j];
				strings[j] = buf;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	ft_sort(argv, argc);
	i = 1;
	while (i < argc)
	{
		ft_print(argv[i++]);
		write(1, "\n", 1);
	}
	return (0);
}
