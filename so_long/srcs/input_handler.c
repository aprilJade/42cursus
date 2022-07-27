/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:16:05 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/23 16:21:19 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "input_handler.h"
#include "drawer.h"
#include "game_manager.h"
#include "ft_error.h"

static void	move_player(t_game_props *props, int next_pos_offset)
{
	int		cur_p_pos;
	int		next_p_pos;

	cur_p_pos = 0;
	while (props->map.data[cur_p_pos] != 'P')
		cur_p_pos++;
	next_p_pos = cur_p_pos + next_pos_offset;
	if (props->map.data[next_p_pos] == '1')
		return ;
	if (props->map.data[next_p_pos] == 'C')
		props->collected_count++;
	else if (props->map.data[next_p_pos] == 'E')
	{
		if (props->collected_count == props->map.chest_count)
			print_err(props, NO_ERROR);
		return ;
	}
	props->map.data[next_p_pos] = 'P';
	props->map.data[cur_p_pos] = '0';
	draw_grass(props, cur_p_pos % props->map.width,
		cur_p_pos / props->map.width);
	draw_player(props, next_p_pos % props->map.width,
		next_p_pos / props->map.width);
	printf("%d\n", ++props->movement_count);
}

int	keyboard_input_listener(int keycode, t_game_props *props)
{
	if (keycode == KEY_ESC)
		print_err(props, NO_ERROR);
	else if (keycode == KEY_W)
		move_player(props, -props->map.width);
	else if (keycode == KEY_S)
		move_player(props, props->map.width);
	else if (keycode == KEY_A)
		move_player(props, -1);
	else if (keycode == KEY_D)
		move_player(props, 1);
	return (0);
}
