/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:19:37 by seonggyk          #+#    #+#             */
/*   Updated: 2022/05/03 11:24:11 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tail_tools.h"
#include "../includes/string_tools.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <libgen.h>
#include <string.h>
#define MEGA_BYTES 1048576

void	ft_print_error(char *program_name, char *file_path)
{
	ft_putstr(basename(program_name));
	ft_putstr(": ");
	ft_putstr(file_path);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

void	print_delimeter(char *file_path)
{
	ft_putstr("==> ");
	ft_putstr(file_path);
	ft_putstr(" <==\n");
}

int	print_one_file(int offset, int fd, char **argv, char *file_path)
{
	int		ret;
	char	*buf;
    int     buf_size;

    buf_size = MEGA_BYTES * 256;
	ret = 1;
	buf = (char *)malloc(sizeof(char) * buf_size);
	while (ret > 0)
	{
		ret = read(fd, buf, buf_size);
		if (ret == 0)
			break ;
		else if (ret < 0)
		{
			ft_print_error(argv[0], file_path);
			continue ;
		}
		if (ret != buf_size)
		{
			write(1, buf + buf_size - offset, offset);
		}
	}
	free(buf);
	return (ret);
}

int	print_bytes(int file_cnt, char **files, int offset, char **argv)
{
	char	*buf;
	int		fd;
	int		i;

	i = 0;
	buf = (char *)malloc(sizeof(char) * MEGA_BYTES * 256);
	while (i < file_cnt)
	{
		fd = open(files[i], O_RDONLY);
		if (fd < 0)
		{
			ft_print_error(argv[0], files[i++]);
			continue ;
		}
		if (file_cnt > 1)
		{
			if (i != 0)
				write(1, "\n", 1);
			print_delimeter(files[i]);
		}
		print_one_file(offset, fd, argv, files[i++]);
		if (fd > 0)
			close(fd);
	}
	return (0);
}
