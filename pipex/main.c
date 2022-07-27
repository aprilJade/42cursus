/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:49:11 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/27 13:40:05 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "string_utils.h"
#include "memory_utils.h"
#include "cmd_parser.h"
#include "errors.h"
#include "pipex_utils.h"

void	pipex(int argc, char **argv, char **envp)
{
	int			filefd[2];
	int			**pipes;
	int			i;
	t_cmd_info	info;
	pid_t		pid;
	
	gen_file_fd(argv[1], argv[argc - 1], filefd);
	argv += 2;
	argc -= 3;
	gen_pipes(argc - 1, &pipes);
	i = 0;
	while (i < argc)
	{
		parse_cmd_info(argv[i], envp, &info);
		pid = fork();
		if (pid == -1)
			print_err_and_exit(NULL);
		else if (pid == 0)
		{
			if (i == 0)
				run_proc(&info, filefd[0], pipes[0][PIPE_WR]);
			else if (i == argc - 1)
				run_proc(&info, pipes[0][PIPE_RD], filefd[1]);				
			run_proc(&info, pipes[i - 1][PIPE_RD], pipes[i][PIPE_WR]);
		}
		if (waitpid(pid, NULL, WNOHANG) == -1)
			print_err_and_exit(NULL);
		i++;
	}
}

int main(int argc, char **argv, char **envp)
{

	if (argc != 5)
		print_err_and_exit("pipex: you need to input arguments more than 4");
	pipex(argc, argv, envp);
}