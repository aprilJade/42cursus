/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:37:27 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/27 13:27:52 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H
# define CHILD_PROCESS 0
# define PIPE_RD 0
# define PIPE_WR 1

typedef struct	s_cmd_info
{
	char	*cmd_path;
	char	**args;
	char	**envp;
}	t_cmd_info;

#endif