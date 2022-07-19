/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 07:04:16 by nekodev           #+#    #+#             */
/*   Updated: 2022/05/01 14:27:22 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i++]) != 0)
			cnt++;
	}
	return (cnt);
}
/*
#include <stdio.h>
int	ft_len(char *str)
{
	char *s;

	s = str;
	while (*str)
		str++;
	return (str - s);
}
int main(void)
{
	char *strs[3];
	strs[0] = "asdf";
	strs[1] = "";
	strs[2] = "";
	printf("%d\n", ft_count_if(strs, 3, ft_len));
}
*/
