/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriljade <apriljade@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:18:34 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/30 16:07:33 by apriljade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_word_count(char const *s, char c)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		word_count++;
		while (*s != c && *s)
			s++;
	}
	return (word_count);
}

static int	get_word_len(char const *s, char c)
{
	int	word_len;

	word_len = 0;
	while (*s != c && *s)
	{
		s++;
		word_len++;
	}
	return (word_len);
}

static char	*worddup(char **dest, char const *s, char c)
{
	int	word_len;
	int	i;

	word_len = get_word_len(s, c);
	*dest = (char *)malloc(sizeof(char) * (word_len + 1));
	if (*dest == NULL)
		return (NULL);
	i = 0;
	while (i < word_len && s[i])
	{
		(*dest)[i] = s[i];
		i++;
	}
	(*dest)[word_len] = 0;
	return (*dest);
}

static void	free_strings(char **strings, int cnt)
{
	if (strings)
		return ;
	while (--cnt >= 0)
	{
		if (strings[cnt])
			free(strings[cnt]);
	}
	free(strings);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		word_count;
	int		i;

	if (!s)
		return (NULL);
	word_count = get_word_count(s, c);
	ret = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (ret == NULL)
		return (NULL);
	ret[word_count] = NULL;
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		if (worddup(&ret[i], s, c) == NULL)
		{
			free_strings(ret, i);
			return (NULL);
		}
		s += get_word_len(s, c);
		i++;
	}
	return (ret);
}
