/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:29:57 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/28 17:26:10 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_UTILS_BONUS_H
# define PIPEX_UTILS_BONUS_H
# define PIPE_RD 0
# define PIPE_WR 1

void	open_files(char *in_path, char *out_path, int *in_fd, int *out_fd);
void	parse_and_exec(char *arg, char **envp);
void	print_err_and_exit(char *custom_msg);

#endif