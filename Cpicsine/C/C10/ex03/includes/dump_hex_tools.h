/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_hex_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:44:19 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/30 22:26:42 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMP_HEX_TOOLS_H
# define DUMP_HEX_TOOLS_H

void	read_error(int fd, char *file_path);
void	print_remain_data(char *data, int size, int flag);
void	init_buffer(char *buffer);
void	charcat(char *dest, char c);
void	print_one_line(char *data, int total_size, int size, int flag);

#endif
