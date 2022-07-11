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
#include <stddef.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remain;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	remain = read_fd(fd, line, remain);
	if (remain == NULL)
		return (NULL);
	line = extract_line(remain);
	if (line == NULL)
		return (NULL);
	remain = update_remain(remain);
	return (line);
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(void)
{
	int fd = open("test1.txt", O_RDONLY); 
	if (fd < 0)
		return 1;
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}
