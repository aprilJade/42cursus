/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:18:59 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/25 18:36:20 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer_bonus.h"
#include "map_drawer_bonus.h"
#include "board_drawer_bonus.h"

int	render(t_game_props *props)
{
	static int	frame_number;

	draw_map(props, frame_number++ / 5);
	draw_board(props);
	return (0);
}
