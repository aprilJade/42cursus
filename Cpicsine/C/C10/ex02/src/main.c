/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:50:41 by seonggyk          #+#    #+#             */
/*   Updated: 2022/05/03 11:21:01 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include "../includes/string_tools.h"
#include "../includes/tail_tools.h"
#include <unistd.h>
#define MIN_ARGC 4
#define INVALID_OFFSET -1

enum e_argv_idx
{
	program_name,
	option,
	offset,
	file_path
};

void	print_err_invalid_offset(char **argv)
{
	ft_putstr(basename(argv[program_name]));
	ft_putstr(": illegal offset -- ");
	ft_putstr(argv[offset]);
	ft_putstr("\n");
}

int	check_opt(int argc, char **argv)
{
	char	c;

	if (argc < MIN_ARGC - 1)
		return (INVALID_OFFSET);
	if (is_number(argv[offset]) == 0)
	{
		print_err_invalid_offset(argv);
		return (INVALID_OFFSET);
	}
	if (argc < MIN_ARGC)
	{
		while (read(0, &c, 1) > 0)
			;
		return (INVALID_OFFSET);
	}
	return (simple_atoi(argv[offset]));
}

int	main(int argc, char **argv)
{
	int	offset;

	offset = check_opt(argc, argv);
	if (offset == INVALID_OFFSET)
		return (EXIT_FAILURE);
	print_bytes(argc - 3, argv + 3, offset, argv);
	return (EXIT_SUCCESS);
}
