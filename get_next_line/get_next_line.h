#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFFER_SIZE 20
char    *extract_line(char *remain);
char    *update_remain(char *remain);
char	*get_next_line(int fd);
char	*read_fd(int fd, char *line, char *remain);
char    *ft_strchr(char *s, char c);
char    *ft_strjoin(char *first, char *second);

#endif