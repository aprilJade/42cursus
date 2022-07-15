/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:11:53 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/14 16:57:10 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*extract_line(char *remain)
{
	char	*line;
	int		i;

	if (*remain == '\0')
		return (NULL);
	i = 0;
	while (remain[i] && remain[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1 + (remain[i] == '\n')));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (remain[i] != '\n' && remain[i])
	{
		line[i] = remain[i];
		i++;
	}
	if (remain[i] == '\n')
	{
		line[i] = remain[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

static char	*update_remain(char *remain)
{
	int	i;
	int	j;

	i = 0;
	while (remain[i] && remain[i] != '\n')
		i++;
	if (remain[i] == '\0')
	{
		free(remain);
		return (NULL);
	}
	i++;
	j = 0;
	while (remain[i])
		remain[j++] = remain[i++];
	remain[j] = 0;
	return (remain);
}

static char	*read_fd(int fd, char *remain)
{
	char	buf[BUFFER_SIZE + 1];
	int		read_cnt;

	read_cnt = 1;
	while (!find_new_line(remain))
	{
		read_cnt = read(fd, buf, BUFFER_SIZE);
		if (read_cnt == 0)
			break ;
		if (read_cnt < 0)
		{
			if (remain)
				free(remain);
			return (NULL);
		}
		buf[read_cnt] = 0;
		remain = ft_strjoin(remain, buf);
	}
	return (remain);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remain;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	remain = read_fd(fd, remain);
	if (remain == NULL)
		return (NULL);
	line = extract_line(remain);
	remain = update_remain(remain);
	return (line);
}
