/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:58:52 by seonggyk          #+#    #+#             */
/*   Updated: 2022/05/01 16:45:56 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include "../includes/print_file.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_print_error(char *program_name, char *file_path)
{
	ft_putstr(basename(program_name));
	ft_putstr(": ");
	ft_putstr(file_path);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

int	print_file(char *program_name, char *file_path)
{
	int		size;
	char	buf[16];
	int		fd;

	fd = file_open(file_path);
	if (fd < 0)
	{
		ft_print_error(program_name, file_path);
		return (-1);
	}
	size = read(fd, buf, 16);
	while (size > 0)
	{
		write(1, buf, size);
		size = read(fd, buf, 16);
	}
	close(fd);
	if (size == 0)
		return (0);
	else
	{
		ft_print_error(program_name, file_path);
		return (-1);
	}
}

int	file_open(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}
