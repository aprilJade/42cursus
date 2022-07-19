/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:20:32 by seonggyk          #+#    #+#             */
/*   Updated: 2022/05/02 10:20:34 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	char	*s;

	s = str;
	while (*str)
		str++;
	return (str - s);
}

int	is_in_charset(char c, char *charset)
{
	while (*charset != 0 && c != *charset)
		charset++;
	if (*charset == 0)
		return (0);
	return (1);
}

int	get_word_count(char *str, char *charset)
{
	int		cnt;
	char	*cs;

	cnt = 0;
	cs = charset;
	while (*str)
	{
		while (is_in_charset(*str, charset) && *str)
			str++;
		if (*str == 0)
			return (cnt);
		while (is_in_charset(*str, charset) == 0 && *str)
			str++;
		cnt++;
	}
	return (cnt);
}

int	get_word_len(char *str, char *charset)
{
	char	*s;

	s = str;
	while (*str)
	{
		if (is_in_charset(*str, charset) == 1)
			break ;
		str++;
	}
	return (str - s);
}

char	**ft_split(char	*str, char *charset)
{
	int		wc;
	char	**ret;
	int		i;
	int		j;
	int		word_len;

	wc = get_word_count(str, charset);
	ret = (char **)malloc(sizeof(char *) * (wc + 1));
	ret[wc] = 0;
	i = 0;
	while (*str)
	{
		while (is_in_charset(*str, charset) == 1 && *str)
			str++;
		if (*str == 0)
			return (ret);
		word_len = get_word_len(str, charset);
		ret[i] = (char *)malloc(sizeof(char) * word_len + 1);
		j = 0;
		while (j < word_len)
			ret[i][j++] = *str++;
		ret[i++][j] = 0;
	}
	return (ret);
}
/*
#include <stdio.h>
int main(void)
{
	char *str = "5C3gRa1iwRABCTRRm2AMwyEkeD43tOyMpeOIv47lIv5mc";
	char *charset = "";
	//char *charset = "gBF786PA";
	//char *str = "asdf";
	//char *charset = "asdf";
	char **ret = ft_split(str, charset);
	for (int i = 0; i < 7; i++)
		printf("%s\n", ret[i]);
	for (int i = 0; i < 5; i++)
		free(ret[i]);
	free(ret);
}
*/
