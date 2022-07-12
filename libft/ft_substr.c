/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:12:58 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/10 19:49:03 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

static int	get_necessary_len(const char *s, unsigned int start, size_t len)
{
	int	s_len;
	int	ret;

	s_len = ft_strlen(s);
	if (s_len <= (int)start)
		return (0);
	ret = s_len - start;
	if (ret > (int)len)
		ret = len;
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*pret;
	int		ret_len;

	if (!s)
		return (NULL);
	ret_len = get_necessary_len(s, start, len);
	if (ret_len < 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ret_len + 1));
	if (ret == NULL)
		return (NULL);
	pret = ret;
	while (ret_len--)
		*pret++ = *(s++ + start);
	*pret = 0;
	return (ret);
}
