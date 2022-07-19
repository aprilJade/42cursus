/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:14:37 by seonggyk          #+#    #+#             */
/*   Updated: 2022/05/01 21:25:30 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_sort_string_tab(char **tab)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (tab[i] != 0)
	{
		j = i + 1;
		while (tab[j] != 0)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
/*
#include <stdio.h>

int main(void)
{
	char *s[5];
	s[0] = "asdf";
	s[1] = "Asdf";
	s[2] = "aaaa";
	s[3] = "sfjeilfi";
	s[4] = 0;
	ft_sort_string_tab(s);
	for (int i = 0; i < 4; i++)
		printf("%s\n", s[i]);
	return 0;
}
*/
