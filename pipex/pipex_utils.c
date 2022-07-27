/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:30:25 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/27 13:40:03 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"
#include "errors.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	gen_file_fd(char *infile_path, char *outfile_path, int fd[2])
{
	fd[0] = open(infile_path, O_RDONLY);
	if (fd[0] < 0)
		print_err_and_exit(NULL);
	fd[1] = open(outfile_path, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd[1] < 0)
		print_err_and_exit(NULL);
}

void	gen_pipes(int size, int ***pipes)
{
	int	**p;
	int	i;

	p = (int **)malloc(sizeof(int *) * size);
	if (p == NULL)
		print_err_and_exit(NULL);
	i = 0;
	while (i < size)
	{
		p[i] = (int *)malloc(sizeof(int) * 2);
		if (p[i] == NULL)
			print_err_and_exit(NULL);
		if (pipe(p[i]) == -1)
			print_err_and_exit(NULL);
		i++;
	}
	*pipes = p;
}

void	run_proc(t_cmd_info *info, int infd, int outfd)
{
	if (dup2(infd, STDIN_FILENO) == -1)
		print_err_and_exit(NULL);
	if (dup2(outfd, STDOUT_FILENO) == -1)
		print_err_and_exit(NULL);
	if (execve(info->cmd_path, info->args, info->envp) == -1)
		print_err_and_exit(NULL);
}