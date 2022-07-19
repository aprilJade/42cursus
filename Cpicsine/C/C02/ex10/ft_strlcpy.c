/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 09:11:09 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/21 08:24:40 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	char	*s;

	s = str;
	while (*str++)
		;
	return (str - s - 1);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char	*s;

	s = src;
	if (size != 0)
	{
		while (*src && --size)
			*dest++ = *src++;
		*dest = '\0';
	}
	return (ft_strlen(s));
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[12];
	int a;
	memset(buf, 0, 12);
	a = ft_strlcpy(buf, "hello", 0);
	printf("%d, %s\n", a, buf);
	memset(buf, 0, 12);
	a = ft_strlcpy(buf, "hello", 5);
	printf("%d, %s\n", a, buf);
	memset(buf, 0, 12);
	a = ft_strlcpy(buf, "hello", 3);
	printf("%d, %s\n", a, buf);

	memset(buf, 0, 12);
	a = strlcpy(buf, "hello", 0);
	printf("%d, %s\n", a, buf);
	memset(buf, 0, 12);
	a = strlcpy(buf, "hello", 5);
	printf("%d, %s\n", a, buf);
	memset(buf, 0, 12);
	a = strlcpy(buf, "hello", 3);
	printf("%d, %s\n", a, buf);
}
*/
