/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:45:27 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/26 17:10:00 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_PARSER_H
# define CMD_PARSER_H
# include "define.h"

void	parse_cmd_info(char *cmd_args,  char **envp, t_cmd_info *output);

#endif