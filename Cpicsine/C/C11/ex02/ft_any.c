/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 07:29:10 by nekodev           #+#    #+#             */
/*   Updated: 2022/05/02 19:34:34 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	while (*tab)
	{
		if (f(*tab++) != 0)
			return (1);
	}
	return (0);
}
/*
int	has_a(char *s)
{
	while (*s)
	{
		if (*s++ == 'a')
			return (1);
	}
	return (0);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	char **strs = (char**)malloc(sizeof(char *) * 3);
	for (int i = 0; i < 2; i++)
		strs[i] = (char *)malloc(sizeof(char) * 3);
	strcpy(strs[0], "hi");
	strcpy(strs[1], "b");
	strs[2] = 0;
	printf("%d\n", ft_any(strs, has_a));
	return (0);
}
*/
