/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:44:18 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/22 16:41:39 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"
#include "mlx.h"
#include "so_long.h"

void	draw_player(t_game_props* props, int x, int y)
{
	mlx_put_image_to_window(props->mlx, props->win, props->imgs[GRASS], IMG_SIZE * x, IMG_SIZE * y);
	mlx_put_image_to_window(props->mlx, props->win, props->imgs[PLAYER], IMG_SIZE * x, IMG_SIZE * y);
}

void	draw_wall(t_game_props* props, int x, int y)
{
	mlx_put_image_to_window(props->mlx, props->win, props->imgs[WALL], IMG_SIZE * x, IMG_SIZE * y);
}

void	draw_grass(t_game_props* props, int x, int y)
{
	mlx_put_image_to_window(props->mlx, props->win, props->imgs[GRASS], IMG_SIZE * x, IMG_SIZE * y);
}

void	draw_chest(t_game_props* props, int x, int y)
{
	mlx_put_image_to_window(props->mlx, props->win, props->imgs[GRASS], IMG_SIZE * x, IMG_SIZE * y);
	mlx_put_image_to_window(props->mlx, props->win, props->imgs[CHEST], IMG_SIZE * x, IMG_SIZE * y);
}

void	draw_door(t_game_props* props, int x, int y)
{
	mlx_put_image_to_window(props->mlx, props->win, props->imgs[GRASS], IMG_SIZE * x, IMG_SIZE * y);
	mlx_put_image_to_window(props->mlx, props->win, props->imgs[DOOR], IMG_SIZE * x, IMG_SIZE * y);
}
