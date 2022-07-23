/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:42:00 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/23 16:25:56 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define IMG_SIZE 64
# define IMG_COUNT 5

typedef struct s_map
{
	char	*data;
	int		width;
	int		height;
	int		player_count;
	int		chest_count;
	int		door_count;
}	t_map;

typedef struct s_game_props
{
	void	*mlx;
	void	*win;
	void	*imgs[IMG_COUNT];
	int		collected_count;
	int		movement_count;
	t_map	map;
}	t_game_props;

enum e_imgName
{
	CHEST,
	WALL,
	PLAYER,
	GRASS,
	DOOR	
};

#endif