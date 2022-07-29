/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_reader_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:54:01 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/26 15:51:09 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image_reader_bonus.h"
#include <stdlib.h>
#include "ft_error_bonus.h"
#include "string_utils_bonus.h"
#include "mlx.h"

static char	*gen_file_path(char *path, int idx)
{
	int		len;
	char	*ret;

	len = 0;
	while (path[len] != '\0')
		len++;
	ret = (char *)malloc(sizeof(char) * (len + 5 + 1));
	if (ret == NULL)
		return (NULL);
	ft_strcpy(ret, path);
	ret[len] = '0' + idx;
	ft_strcpy(ret + len + 1, ".xpm");
	return (ret);
}

static void	read_player_images(t_game_props *props)
{
	int		x;
	int		y;
	int		i;
	char	*file_path;

	i = 0;
	while (i < PLAYER_IMG_COUNT)
	{
		file_path = gen_file_path("./sprites/player/", i + 1);
		if (file_path == NULL)
			print_err(props, FILE_ERROR);
		props->imgs.player[i++] = mlx_xpm_file_to_image(props->mlx,
				file_path, &x, &y);
		free(file_path);
	}
}

static void	read_collectible_images(t_game_props *props)
{
	int		x;
	int		y;
	int		i;
	char	*file_path;

	i = 0;
	while (i < COLLECTIBLE_IMG_COUNT)
	{
		file_path = gen_file_path("./sprites/collectible/", i + 1);
		if (file_path == NULL)
			print_err(props, FILE_ERROR);
		props->imgs.collectible[i++] = mlx_xpm_file_to_image(props->mlx,
				file_path, &x, &y);
		free(file_path);
	}
}

static void	read_enemy_images(t_game_props *props)
{
	int		x;
	int		y;
	int		i;
	char	*file_path;

	i = 0;
	while (i < ENEMY_IMG_COUNT)
	{
		file_path = gen_file_path("./sprites/enemy/", i + 1);
		if (file_path == NULL)
			print_err(props, FILE_ERROR);
		props->imgs.enemy[i++] = mlx_xpm_file_to_image(props->mlx,
				file_path, &x, &y);
		free(file_path);
	}
}

void	read_images(t_game_props *props)
{
	int	x;
	int	y;

	props->imgs.road = mlx_xpm_file_to_image(props->mlx,
			"./sprites/road.xpm", &x, &y);
	props->imgs.door = mlx_xpm_file_to_image(props->mlx,
			"./sprites/door.xpm", &x, &y);
	props->imgs.wall = mlx_xpm_file_to_image(props->mlx,
			"./sprites/wall.xpm", &x, &y);
	read_player_images(props);
	read_enemy_images(props);
	read_collectible_images(props);
}
