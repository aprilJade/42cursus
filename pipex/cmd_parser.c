/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:46:06 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/27 12:13:05 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_parser.h"
#include "string_utils.h"
#include "memory_utils.h"
#include "errors.h"
#include <stdlib.h>
#include <unistd.h>

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

static char	*extract_cmd(char *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != ' ')
		len++;
	return (ft_strndup(s, len));
}

void	parse_cmd_info(char *cmd_args,  char **envp, t_cmd_info *output)
{
	static int	idx;
	
	idx = find_path_env_index(envp);
	output->cmd_path = gen_cmd_path(extract_cmd(cmd_args), envp[idx]);
	output->args = ft_split(cmd_args, ' ');
	output->envp = envp;
}
