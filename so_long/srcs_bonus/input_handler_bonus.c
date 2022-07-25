/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:16:05 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/25 18:15:03 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "input_handler_bonus.h"
#include "drawer_bonus.h"
#include "game_manager_bonus.h"
#include "ft_error_bonus.h"
#include "string_utils_bonus.h"

static void	move_player(t_game_props *props, int next_pos_offset)
{
	int		cur_p_pos;
	int		next_p_pos;

	cur_p_pos = 0;
	while (props->map.data[cur_p_pos] != PLAYER)
		cur_p_pos++;
	next_p_pos = cur_p_pos + next_pos_offset;
	if (props->map.data[next_p_pos] == WALL)
		return ;
	if (props->map.data[next_p_pos] == DOOR)
	{
		if (props->collected_count == props->map.chest_count)
			print_err(props, NO_ERROR);
		return ;
	}
	if (props->map.data[next_p_pos] == ENEMY)
		print_err(props, NO_ERROR);
	if (props->map.data[next_p_pos] == COLLECTIBLE)
		props->collected_count++;
	props->map.data[next_p_pos] = 'P';
	props->map.data[cur_p_pos] = '0';
	props->movement_count++;
}

int	keyboard_input_listener(int keycode, t_game_props *props)
{
	int	next_pos_offset;

	next_pos_offset = 0;
	if (keycode == KEY_ESC)
		print_err(props, NO_ERROR);
	else if (keycode == KEY_W)
		next_pos_offset = -props->map.width;
	else if (keycode == KEY_S)
		next_pos_offset = props->map.width;
	else if (keycode == KEY_A)
		next_pos_offset = -1;
	else if (keycode == KEY_D)
		next_pos_offset = 1;
	else
		return (0);
	move_player(props, next_pos_offset);
	return (0);
}
