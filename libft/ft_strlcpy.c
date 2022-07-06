/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:34:06 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/05 21:40:23 by seonggyk         ###   ########.fr       */
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

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ret;

	ret = ft_strlen(src);
	i = 1;
	while (*src && i++ < size)
		*dst++ = *src++
	return (ret);
}
