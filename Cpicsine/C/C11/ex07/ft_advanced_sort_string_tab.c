/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:14:37 by seonggyk          #+#    #+#             */
/*   Updated: 2022/05/03 10:43:23 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_tab_cnt(char **tab)
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

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		flag;
	char	*tmp;

	flag = 0;
	while (flag == 0)
	{
		flag = 1;
		i = -1;
		while (tab[++i + 1])
		{
			if ((*cmp)(tab[i], tab[i + 1]) > 0)
			{
				flag = 0;
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
		}
	}
}
/*
#include <stdio.h>
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
int main(void)
{
	char *s[14];
	s[0] = "fJyhDuam";
	s[1] = "2WK";
	s[2] = "caLE";
	s[3] = "h1yxpoGUHzlw";
	s[4] = "AoTzcl";
	s[5] = "Hd3";
	s[6] = "v";
	s[7] = "cE6OLrNqB93";
	s[8] = "IPGD1u";
	s[9] = "9od8";
	s[10] = "HpPbNB1dZiEX";
	s[11] = "NkvB";
	s[12] = "2tF49obm";
	s[13] = 0;
	ft_advanced_sort_string_tab(s, ft_strcmp);
	for (int i = 0; i < 14; i++)
		printf("%s\n", s[i]);
	return 0;
}
*/
