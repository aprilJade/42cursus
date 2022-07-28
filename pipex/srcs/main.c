/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:49:11 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/28 17:58:15 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "pipex_utils.h"

void	run_proc(char *arg, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		print_err_and_exit(NULL);
	pid = fork();
	if (pid == -1)
		print_err_and_exit(NULL);
	if (pid == 0)
	{
		close(pipe_fd[PIPE_RD]);
		if (dup2(pipe_fd[PIPE_WR], STDOUT_FILENO) == -1)
			print_err_and_exit(NULL);
		parse_and_exec(arg, envp);
	}
	else
	{
		close(pipe_fd[PIPE_WR]);
		if (dup2(pipe_fd[PIPE_RD], STDIN_FILENO) == -1)
			print_err_and_exit(NULL);
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	infile_fd;
	int	outfile_fd;
	int	i;

	if (argc != 5)
		print_err_and_exit("Error: You must input 4 arguments\n");
	i = 2;
	open_files(argv[1], argv[argc - 1], &infile_fd, &outfile_fd);
	dup2(infile_fd, STDIN_FILENO);
	while (i < argc - 2)
		run_proc(argv[i++], envp);
	dup2(outfile_fd, STDOUT_FILENO);
	parse_and_exec(argv[argc - 2], envp);
}
