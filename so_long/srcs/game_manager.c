/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:59:06 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/25 18:41:12 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game_manager.h"
#include "mlx.h"
#include "map_drawer.h"
#include "map_validator.h"
#include "map_reader.h"

void	init_game(t_game_props *props, char *map_name)
{
	int	x;
	int	y;

	read_map(props, map_name);
	check_map_validation(props);
	props->mlx = mlx_init();
	props->win = mlx_new_window(props->mlx,
			props->map.width * IMG_SIZE,
			props->map.height * IMG_SIZE,
			"so_long");
	props->imgs[CHEST] = mlx_xpm_file_to_image(props->mlx,
			"./sprites/m_chest.xpm", &x, &y);
	props->imgs[WALL] = mlx_xpm_file_to_image(props->mlx,
			"./sprites/m_wall.xpm", &x, &y);
	props->imgs[PLAYER] = mlx_xpm_file_to_image(props->mlx,
			"./sprites/m_dino.xpm", &x, &y);
	props->imgs[GRASS] = mlx_xpm_file_to_image(props->mlx,
			"./sprites/m_grass.xpm", &x, &y);
	props->imgs[DOOR] = mlx_xpm_file_to_image(props->mlx,
			"./sprites/m_door.xpm", &x, &y);
	draw_map(props);
}

int	end_game(t_endgame_param *param)
{
	int	i;

	if (param->props->map.data)
		free(param->props->map.data);
	i = 0;
	while (i < IMG_COUNT)
	{
		if (param->props->mlx && param->props->imgs[i])
			mlx_destroy_image(param->props->mlx, param->props->imgs[i]);
		i++;
	}
	if (param->props->mlx && param->props->win)
	{
		mlx_clear_window(param->props->mlx, param->props->win);
		mlx_destroy_window(param->props->mlx, param->props->win);
	}
	exit(param->err_code);
}
