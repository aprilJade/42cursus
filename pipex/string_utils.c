/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:34:46 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/26 15:54:01 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"
#include "errors.h"
#include <stdlib.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, int n)
{
	while (*s1 && *s2 && n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_strchr(char *s, char c)
{
	while (*s)
		if (*s++ == c)
			return (s - 1);
	return (s);
}

void	ft_strncpy(char *dst, char *src, int n)
{
	while (*src && n--)
		*dst++ = *src++;
	*dst = 0;
}

int		ft_strlen(char *s)
{
	char	*p;

	p = s;
	while (*s)
		s++;
	return (s - p);	
}

char	*ft_strndup(char *src, int n)
{
	char	*ret;
	int		len;

	len = ft_strlen(src);
	len = len > n ? n : len;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		print_err_and_exit("Error: fail to malloc\n");
	ft_strncpy(ret, src, len);
	return (ret);
}
