#include "get_next_line.h"
#include <stdlib.h>

static int  ft_strlen(char *s)
{
    char    *ps;

    ps = s;
    while (*s)
        s++;
    return (s - ps);
}

static char    *ft_strdup(char *s)
{
    char    *new_str;
    char    *ps;

    new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (new_str == NULL)
        return (NULL);
    ps = new_str;
    while (*s)
        *ps++ = *s;
    *ps = 0;
    return (new_str);
}

static char    *ft_strcpy(char *d, char *s)
{
    while (*s)
        *d++ = *s++;
    *d = 0;
    return (d);
}

char    *ft_strchr(char *s, char c)
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

char    *ft_strjoin(char *first, char *second)
{
    int i;
    int j;
    char    *ret;

	if (first == NULL)
		first = ft_strdup("");
    if (first == NULL)
        return (NULL);
    i = 0;
	while (first[i])
		i++;
    while (second[j])
        j++;
    ret = (char *)malloc(sizeof(char) * (i + j + 1));
    if (ret == NULL)
        return (NULL);
    i = 0;
    ft_strcpy(ret, first);
	free(first);
    j = 0;
    while (second[j])
        ret[i++] = second[j++];
    ret[i] = 0;
    return (ret);
}