/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:59:06 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/25 18:34:01 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game_manager_bonus.h"
#include "mlx.h"
#include "map_drawer_bonus.h"
#include "map_validator_bonus.h"
#include "map_reader_bonus.h"
#include "image_reader_bonus.h"
#include "image_remover_bonus.h"

static void	init_draw_func_table(t_game_props *props)
{
	int	i;

	i = 0;
	while (i < FUNCTION_TABLE_SIZE)
		props->draw_functions[i++] = NULL;
	props->draw_functions[PLAYER] = draw_player;
	props->draw_functions[WALL] = draw_wall;
	props->draw_functions[ROAD] = draw_road;
	props->draw_functions[DOOR] = draw_door;
	props->draw_functions[COLLECTIBLE] = draw_collectible;
	props->draw_functions[ENEMY] = draw_enemy;
}

void	init_game(t_game_props *props, char *map_name)
{
	read_map(props, map_name);
	check_map_validation(props);
	props->mlx = mlx_init();
	props->win = mlx_new_window(props->mlx,
			props->map.width * IMG_SIZE,
			props->map.height * IMG_SIZE,
			"so_long");
	read_images(props);
	init_draw_func_table(props);
}

int	end_game(t_endgame_param *param)
{
	if (param->props->map.data)
		free(param->props->map.data);
	release_images(param->props);
	if (param->props->mlx && param->props->win)
	{
		mlx_clear_window(param->props->mlx, param->props->win);
		mlx_destroy_window(param->props->mlx, param->props->win);
	}
	exit(param->err_code);
}
