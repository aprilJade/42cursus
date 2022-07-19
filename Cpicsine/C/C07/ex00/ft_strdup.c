/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:45:17 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/25 11:48:52 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*s;
	int		len;
	char	*ret;

	len = 0;
	while (src[len])
		len++;
	s = (char *)malloc(sizeof(char) * len + 1);
	ret = s;
	while (*src)
		*s++ = *src++;
	*s = 0;
	return (ret);
}
/*
#include <stdio.h>
int main(void)
{
	char *s = ft_strdup("hello, world!\n");
	printf("%s\n", s);
	free(s);
}
*/
