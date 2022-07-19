/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:21:06 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/25 15:30:04 by seonggyk         ###   ########.fr       */
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

int	get_sum_len(int size, char **strs, char *sep)
{
	int	sep_len;
	int	strs_len;
	int	i;

	sep_len = ft_strlen(sep);
	i = 0;
	strs_len = 0;
	while (i < size)
		strs_len += ft_strlen(strs[i++]);
	return (strs_len + (sep_len * (size - 1)));
}

char	*ft_strcat(char *dest, char *str)
{
	while (*str)
		*dest++ = *str++;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		ret_len;
	int		i;
	char	*s;

	ret_len = get_sum_len(size, strs, sep);
	if (size == 0)
		ret_len = 0;
	s = (char *)malloc(sizeof(char) * ret_len + 1);
	i = 0;
	ret = s;
	while (i < size)
	{
		s = ft_strcat(s, strs[i++]);
		if (i != size)
			s = ft_strcat(s, sep);
	}
	*s = 0;
	return (ret);
}
/*
#include <stdio.h>

int main(void)
{
	char **strs = (char **)malloc(sizeof(char *) * 3);
	strs[0] = "asdf";
	strs[1] = "asdf";
	strs[2] = "asdf";
	char *sep = ", ";
	printf("%s", ft_strjoin(3, strs, sep));
	free(strs);
}
*/
