/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:03:14 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/25 18:35:46 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_drawer_bonus.h"

void	draw_map(t_game_props *props, int cur_frame)
{
	int		h;
	int		w;
	int		idx;
	void	(*draw)(t_game_props *, int, int, int);

	h = 0;
	while (h < props->map.height)
	{
		w = 0;
		while (w < props->map.width)
		{
			idx = (h * props->map.width) + w;
			draw = props->draw_functions[(int)props->map.data[idx]];
			if (draw == 0)
				continue ;
			draw(props, w, h, cur_frame);
			w++;
		}
		h++;
	}
}
