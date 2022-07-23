/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:20:38 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/23 16:25:22 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_READER_H
# define MAP_READER_H
# define BUFFER_SIZE	1024 * 8
# include "so_long.h"

void	read_map(t_game_props *props, char *map_name);

#endif