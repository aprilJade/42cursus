/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:30:25 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/28 17:57:09 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"
#include "string_utils.h"
#include "memory_utils.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

static int	find_path_env_index(char **envp)
{
	int	ret;

	ret = 0;
	while (envp[ret])
		if (ft_strncmp("PATH=", envp[ret++], 5) == 0)
			return (ret - 1);
	print_err_and_exit("pipex: no environment variable: PATH\n");
	return (0);
}

static char	*gen_cmd_path(char *cmd, char *envp_path)
{
	char	*ret;
	char	*pos;
	int		len;

	ret = (char *)malloc(sizeof(char) * 1024);
	if (ret == NULL)
		print_err_and_exit(NULL);
	envp_path += 5;
	while (1)
	{
		ft_memset(ret, 0, 1024);
		pos = ft_strchr(envp_path, ':');
		len = pos - envp_path;
		ft_strncpy(ret, envp_path, len);
		ret[len] = '/';
		ft_strncpy(ret + len + 1, cmd, ft_strlen(cmd));
		if (access(ret, X_OK) == 0)
			return (ret);
		if (*pos == '\0')
			break ;
		envp_path = pos + 1;
	}
	print_err_and_exit(NULL);
	return (0);
}

void	open_files(char *in_path, char *out_path, int *in_fd, int *out_fd)
{
	*in_fd = open(in_path, O_RDONLY);
	if (*in_fd < 0)
		print_err_and_exit(NULL);
	*out_fd = open(out_path, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (*out_fd < 0)
		print_err_and_exit(NULL);
}

void	parse_and_exec(char *arg, char **envp)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_args = ft_split(arg, ' ');
	if (cmd_args == NULL)
		print_err_and_exit("Error: Fail to parse arguments\n");
	cmd_path = gen_cmd_path(cmd_args[0], envp[find_path_env_index(envp)]);
	if (execve(cmd_path, cmd_args, envp) == -1)
		print_err_and_exit(NULL);
}

void	print_err_and_exit(char *custom_msg)
{
	if (custom_msg)
		write(STDERR_FILENO, custom_msg, ft_strlen(custom_msg));
	else
		perror("pipex");
	exit(EXIT_FAILURE);
}
