/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:03:14 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/23 13:48:34 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_drawer.h"

void	draw_map(t_game_props* props)
{
	int	h;
	int	w;
	t_map	*map = &props->map;
	
	h = 0;
	while (h < map->height)
	{
		w = 0;
		while (w < map->width)
		{
			if (map->data[(h * map->width) + w] == '1')
				draw_wall(props, w, h);
			else if (map->data[(h * map->width) + w] == '0')
				draw_grass(props, w, h);
			else if (map->data[(h * map->width) + w] == 'P')
				draw_player(props, w, h);
			else if (map->data[(h * map->width) + w] == 'E')
				draw_door(props, w, h);
			else if (map->data[(h * map->width) + w] == 'C')
				draw_chest(props, w, h);
			w++;
		}
		h++;
	}
}