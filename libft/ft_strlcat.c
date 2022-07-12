/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:42:04 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/12 15:10:22 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	ft_strlen(char const *str)
{
	char const	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i_d;
	size_t	i_s;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	i_d = dest_len;
	i_s = 0;
	while (src[i_s] && i_d + 1 < size)
		dest[i_d++] = src[i_s++];
	dest[i_d] = 0;
	return (dest_len + src_len);
}
