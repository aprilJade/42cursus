/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:48:54 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/10 19:48:09 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char const *s)
{
	char	*str;

	str = (char *)s;
	while (*s)
		s++;
	return (s - str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*hret;

	if (!s1 || !s2)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ret == NULL)
		return (NULL);
	hret = ret;
	while (*s1)
		*hret++ = *s1++;
	while (*s2)
		*hret++ = *s2++;
	*hret = 0;
	return (ret);
}
