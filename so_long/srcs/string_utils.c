/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:09:31 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/23 15:42:33 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"
#include <unistd.h>

void	ft_putstr(char *s)
{
	while (*s)
		write(STDERR_FILENO, s++, 1);
}

int	ft_strlen(char *s)
{
	char	*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_strcpy(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = 0;
}

void	ft_memset(void *dst, int value, int size)
{
	unsigned char	*p;
	int				i;

	p = dst;
	i = 0;
	while (i < size)
		p[i++] = value;
}