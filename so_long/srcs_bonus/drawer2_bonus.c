/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:30:38 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/25 16:42:47 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer_bonus.h"
#include "mlx.h"
#include "so_long_bonus.h"

void	draw_collectible(t_game_props *props, int x, int y, int cur_frame)
{
	draw_road(props, x, y, cur_frame);
	mlx_put_image_to_window(props->mlx,
		props->win, props->imgs.collectible[cur_frame % COLLECTIBLE_IMG_COUNT],
		IMG_SIZE * x, IMG_SIZE * y);
}

void	draw_player(t_game_props *props, int x, int y, int cur_frame)
{
	draw_road(props, x, y, cur_frame);
	mlx_put_image_to_window(props->mlx,
		props->win, props->imgs.player[cur_frame % PLAYER_IMG_COUNT],
		IMG_SIZE * x, IMG_SIZE * y);
}

void	draw_enemy(t_game_props *props, int x, int y, int cur_frame)
{
	draw_road(props, x, y, cur_frame);
	mlx_put_image_to_window(props->mlx,
		props->win, props->imgs.enemy[cur_frame % ENEMY_IMG_COUNT],
		IMG_SIZE * x, IMG_SIZE * y);
}
