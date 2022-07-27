/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:03:14 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/23 17:33:48 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_drawer.h"

void	draw_map(t_game_props *props)
{
	int	h;
	int	w;

	h = 0;
	while (h < props->map.height)
	{
		w = 0;
		while (w < props->map.width)
		{
			if (props->map.data[(h * props->map.width) + w] == '1')
				draw_wall(props, w, h);
			else if (props->map.data[(h * props->map.width) + w] == '0')
				draw_grass(props, w, h);
			else if (props->map.data[(h * props->map.width) + w] == 'P')
				draw_player(props, w, h);
			else if (props->map.data[(h * props->map.width) + w] == 'E')
				draw_door(props, w, h);
			else if (props->map.data[(h * props->map.width) + w] == 'C')
				draw_chest(props, w, h);
			w++;
		}
		h++;
	}
}
