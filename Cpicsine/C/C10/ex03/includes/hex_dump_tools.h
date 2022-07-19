/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_dump_tools.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:17:31 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/30 21:08:02 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEX_DUMP_TOOLS_H
# define HEX_DUMP_TOOLS_H

void	print_number_in_hex(int number, char *hex);
void	print_index_in_hex(int size, int flag, int last);
void	print_data_in_hex(unsigned char *data, int size, int flag);
void	print_data_in_ascii(unsigned char *data, int size);
void	print_spaces(int len);

#endif
