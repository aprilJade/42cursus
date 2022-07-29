/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_remover_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:31:56 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/25 18:35:12 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image_remover_bonus.h"
#include "mlx.h"

static void	remove_single_images(t_game_props *props)
{
	if (props->imgs.road)
		mlx_destroy_image(props->mlx, props->imgs.road);
	if (props->imgs.door)
		mlx_destroy_image(props->mlx, props->imgs.door);
	if (props->imgs.wall)
		mlx_destroy_image(props->mlx, props->imgs.wall);
}

static void	remove_multiple_images(t_game_props *props)
{
	int	i;

	i = 0;
	while (i < PLAYER_IMG_COUNT)
	{
		if (props->imgs.player[i])
			mlx_destroy_image(props->mlx, props->imgs.player[i]);
		i++;
	}
	i = 0;
	while (i < COLLECTIBLE_IMG_COUNT)
	{
		if (props->imgs.collectible[i])
			mlx_destroy_image(props->mlx, props->imgs.collectible[i]);
		i++;
	}
	i = 0;
	while (i < ENEMY_IMG_COUNT)
	{
		if (props->imgs.enemy[i])
			mlx_destroy_image(props->mlx, props->imgs.enemy[i]);
		i++;
	}
}

void	release_images(t_game_props *props)
{
	remove_multiple_images(props);
	remove_single_images(props);
}
