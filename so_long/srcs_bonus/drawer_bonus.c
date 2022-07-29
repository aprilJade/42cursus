/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:44:18 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/25 16:30:54 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer_bonus.h"
#include "mlx.h"
#include "so_long_bonus.h"

void	draw_wall(t_game_props *props, int x, int y, int cur_frame)
{
	cur_frame = 0;
	mlx_put_image_to_window(props->mlx,
		props->win, props->imgs.wall, IMG_SIZE * x, IMG_SIZE * y);
}

void	draw_road(t_game_props *props, int x, int y, int cur_frame)
{
	cur_frame = 0;
	mlx_put_image_to_window(props->mlx,
		props->win, props->imgs.road, IMG_SIZE * x, IMG_SIZE * y);
}

void	draw_door(t_game_props *props, int x, int y, int cur_frame)
{
	draw_road(props, x, y, cur_frame);
	mlx_put_image_to_window(props->mlx,
		props->win, props->imgs.door, IMG_SIZE * x, IMG_SIZE * y);
}
