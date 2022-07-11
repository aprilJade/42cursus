#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFFER_SIZE 100
char    *extract_line(char *remain);
char    *update_remain(char *remain);
char	*get_next_line(int fd);
char	*read_fd(int fd, char *line, char *remain);

#endif