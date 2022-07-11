#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char    *ft_strchr(char *s, char c)
{
    if (s == NULL)
        return (NULL);
    while (*s)
    {
        if (*s == c)
            return (s);
        s++;
    }
    return (NULL);
}

static char    *ft_strjoin(char *first, char *second)
{
    int i;
    int j;
    char    *ret;

    if (first != NULL)
        while (first[i])
            i++;
    while (second[j])
        j++;
    ret = (char *)malloc(sizeof(char) * (i + j + 1));
    if (ret == NULL)
        return (NULL);
    i = 0;
    if (first != NULL)
    {
        while (first[i])
        {
            ret[i] = first[i];    
            i++;
        }
        free(first);
    }
    j = 0;
    while (second[j])
        ret[i++] = second[j++];
    ret[i] = 0;
    return (ret);
}

char    *extract_line(char *remain)
{
    char    *line;
    int     i;
    int     j;

    i = 0;
    while (remain[i] && remain[i] != '\n')
        i++;
    line = (char *)malloc(sizeof(char) * (i + 2));
    if (line == NULL)
        return (NULL);
    i = 0;
    while (remain[i] != '\n' && remain[i])
    {
        line[i] = remain[i];
        i++;
    }
    if (remain[i] == '\n' && remain[i])
    {
        line[i] = remain[i];
        i++;
    }
    line[i] = 0;
    return (line);
}

char    *update_remain(char *remain)
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

char	*read_fd(int fd, char *line, char *remain)
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
            return (remain);
		if (read_cnt < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[read_cnt] = 0;
		remain = ft_strjoin(remain, buf);
	}
	free(buf);
	return (remain);
}