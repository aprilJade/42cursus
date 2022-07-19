/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 08:34:32 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/21 08:36:12 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	char	*s;

	s = str;
	while (*str++)
		;
	return (str - s - 1);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_strlen(""));
	printf("%d\n", ft_strlen("asdf"));
}
*/
