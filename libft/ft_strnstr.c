/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:41:17 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/12 10:39:36 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

static int	ft_strcmp(unsigned char *l, unsigned char *r)
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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	big_len;
	size_t	i;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	big_len = ft_strlen(big);
	if (big_len > len)
		big_len = len;
	if (big_len < little_len)
		return (NULL);
	i = 0;
	while (i <= big_len - little_len)
	{
		if (ft_strcmp((unsigned char *)big + i, (unsigned char *)little) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
