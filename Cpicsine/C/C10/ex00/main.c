/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:50:41 by seonggyk          #+#    #+#             */
/*   Updated: 2022/05/01 16:01:35 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 256

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	print_file(char *buf, char *file_path)
{
	int	size;
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (-1);
	}
	size = read(fd, buf, BUF_SIZE);
	while (size > 0)
	{
		write(1, buf, size);
		size = read(fd, buf, BUF_SIZE);
		if (size < 0)
			return (-1);
	}
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	char	buf[BUF_SIZE];

	if (argc == 1)
	{
		ft_putstr("File name missing.\n");
		return (-1);
	}
	if (argc >= 3)
	{
		ft_putstr("Too many arguments.\n");
		return (-1);
	}
	if (print_file(buf, argv[1]) == -1)
	{
		ft_putstr("Cannot read file.\n");
		return (-1);
	}
	return (0);
}
