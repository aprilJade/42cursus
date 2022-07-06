/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:18:45 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/05 22:24:45 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char *s)
{
	const char	*ps;

	ps = s;
	while (*ps)
		ps++;
	return (ps - p);
}

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*ret;

	len = ft_strlen(s) + 1;
	ret = (char *)malloc(sizeof(char) * len);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len)
		ret[i++] = s[i];
	return (ret);
}
