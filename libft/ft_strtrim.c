/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:54:13 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/13 18:09:36 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	make_set_table(char const *set, char *table)
{
	int		i;

	i = 0;
	while (i < 128)
		table[i++] = 0;
	while (*set)
		table[(int)*set++] = 1;
}

static void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (*src && i++ < n)
		*dest++ = *src++;
}

static char	*make_empty_string(void)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char));
	if (ret == NULL)
		return (NULL);
	*ret = 0;
	return (ret);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char		*ret;
	char		*start_addr;
	char		*end_addr;
	char		set_table[128];

	if (!s || !set)
		return (NULL);
	make_set_table(set, set_table);
	while (set_table[(int)*s])
		s++;
	if (*s == '\0')
		return (make_empty_string());
	start_addr = (char *)s;
	while (*s)
		s++;
	s--;
	while (set_table[(int)*s])
		s--;
	end_addr = (char *)s;
	ret = (char *)malloc(sizeof(char) * (end_addr - start_addr + 2));
	if (ret == NULL)
		return (NULL);
	ft_strncpy(ret, (char *)start_addr, end_addr - start_addr + 1);
	ret[end_addr - start_addr + 1] = 0;
	return (ret);
}
