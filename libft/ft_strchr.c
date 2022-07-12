/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:24:28 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/08 13:53:30 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

char	*ft_strchr(const char *str, int c)
{
	if (c == 0)
		return ((char *)(str + ft_strlen(str)));
	while (*str)
		if (*str++ == (char)c)
			return ((char *)str - 1);
	return (0);
}
