/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:11:53 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/11 17:39:19 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char    *extract_line(char *remain)
{
    char    *line;
    int     i;

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

static char    *update_remain(char *remain)
{
    int i;
    int j;

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
	char	*buf;
	int		read_cnt;
	
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_cnt = 1;
	while (!ft_strchr(remain, '\n'))
	{
		read_cnt = read(fd, buf, BUFFER_SIZE);
        if (read_cnt == 0)
            break;
		if (read_cnt < 0)
		{
			free(buf);
            if (remain)
                free(remain);
			return (NULL);
		}
		buf[read_cnt] = 0;
		remain = ft_strjoin(remain, buf);
	}
	free(buf);
	return (remain);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remain[10240];	// TODO: remove magic number

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	remain[fd] = read_fd(fd, remain[fd]);
	if (remain[fd] == NULL)
		return (NULL);
	line = extract_line(remain[fd]);
	if (line == NULL)
		return (NULL);
	remain[fd] = update_remain(remain[fd]);
	return (line);
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(void)
{
	int fd1 = open("test1.txt", O_RDONLY); 
	if (fd1 < 0)
		return 1;
	int fd2 = open("test2.txt", O_RDONLY); 
	if (fd2 < 0)
		return 1;
	int fd3 = open("test3.txt", O_RDONLY); 
	if (fd3 < 0)
		return 1;
	char *line;
	for (int i = 0; i < 3; i++)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
		line = get_next_line(fd3);
		printf("%s", line);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}
