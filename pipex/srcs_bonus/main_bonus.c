/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:49:11 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/28 20:07:34 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "pipex_utils_bonus.h"
#include "string_utils_bonus.h"

static void	run_proc(char *arg, char **envp)
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

static char	*add_post_newline(char *s)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 2));
	if (ret == NULL)
		print_err_and_exit("Error: Fail to malloc\n");
	ft_strncpy(ret, s, ft_strlen(s));
	ret[ft_strlen(s)] = '\n';
	ret[ft_strlen(s) + 1] = 0;
	return (ret);
}

static void do_rd_wr(char *limiter, int len, int pipe_fd[2])
{
	char    buf[1024];
    int     size;
    int     total_size;
	pipe_fd = 0;
    size = 0;
    total_size = 0;
    while (1)
    {
        size = read(0, buf + total_size, 1024 - total_size);
        if (size == -1)
            print_err_and_exit(NULL);
        total_size += size;
		if (total_size < len + 1)
			continue;
		printf("%s", buf);
        if (ft_strncmp(buf + total_size - len - 1, limiter, len + 1) == 0)
        {
            write(1, buf, total_size - len - 1);
			free(limiter);
            exit(0);
        }
        if (total_size > 1000)
        {
            write(1, buf, total_size);
            total_size = 0;
            size = 0;
        }
    }
}

static void	here_doc(char *limiter)
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
		do_rd_wr(add_post_newline(limiter), ft_strlen(limiter), pipe_fd);
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

	if (argc < 5)
		print_err_and_exit("Error: You must input least 4 arguments\n");
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
	{
		i = 3;
		if (argc < 6)
			print_err_and_exit("Error: For here_doc, you must input least 5 arguments\n");
		outfile_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (outfile_fd < 0)
			print_err_and_exit(NULL);
		here_doc(argv[2]);
	}
	else
	{
		i = 2;
		open_files(argv[1], argv[argc - 1], &infile_fd, &outfile_fd);
		dup2(infile_fd, STDIN_FILENO);
	}
	while (i < argc - 2)
		run_proc(argv[i++], envp);
	dup2(outfile_fd, STDOUT_FILENO);
	parse_and_exec(argv[argc - 2], envp);
}
