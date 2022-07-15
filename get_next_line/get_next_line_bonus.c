/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:11:53 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/15 13:47:59 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#ifndef OPEN_MAX
# define OPEN_MAX 256
#endif

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
	static char	*remain[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX - 1 || BUFFER_SIZE < 1)
		return (NULL);
	remain[fd] = read_fd(fd, remain[fd]);
	if (remain[fd] == NULL)
		return (NULL);
	line = extract_line(remain[fd]);
	remain[fd] = update_remain(remain[fd]);
	return (line);
}
