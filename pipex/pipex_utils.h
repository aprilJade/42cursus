/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:29:57 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/27 13:40:00 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_UTILS_H
# define PIPEX_UTILS_H
# include "define.h"

void	gen_file_fd(char *infile_path, char *outfile_path, int fd[2]);
void	gen_pipes(int size, int ***pipes);
void	run_proc(t_cmd_info *info, int infd, int outfd);

#endif