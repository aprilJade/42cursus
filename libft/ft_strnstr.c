/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:41:17 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/05 21:59:33 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_strlen(char *str)
{
	char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

static int	ft_strcmp(char *l, char *r)
{
	while (*l && *r)
	{
		if (*l != *r)
			return (*l - *r);
		l++;
		r++;
	}
	return (0);
}

char	*strnstr(const char *big, const char *little, size_t len)
{
	int	littleLen;
	int bigLen;
	int	i;

	if (little == NULL)
		return (NULL);
	littleLen = ft_strlen(little);
	if (littleLen == 0)
		return (NULL);
	bigLen = ft_strlen(big);
	if (bigLen > len)
		bigLen = len;
	while (i <= bigLen - littleLen)
	{
		if (ft_strcmp(big + i, little) == 0)
			return (big + i);
		i++;
	}
	return (NULL);
}
