/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:50:41 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/26 22:15:25 by apriljade        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/print_file.h"
#include <unistd.h>
#define EXIT_FAILURE 8
#define EXIT_SUCCESS 0

int	read_mode(void)
{
	int		size;
	char	buf[16];

	size = 1;
	while (size > 0)
	{
		size = read(0, buf, 16);
		if (size > 0)
			write(1, buf, size);
		else if (size < 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	if (argc > 1)
	{
		while (i < argc)
		{
			ret = print_file(argv[0], argv[i++]);
			if (ret < 0)
				ret = EXIT_FAILURE;
		}
	}
	else if (argc == 1)
		ret = read_mode();
	return (ret);
}
