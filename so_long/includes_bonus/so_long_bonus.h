/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:42:00 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/25 17:59:57 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define FUNCTION_TABLE_SIZE 256
# define IMG_SIZE 32
# define IMG_COUNT 6
# define PLAYER_IMG_COUNT 8
# define COLLECTIBLE_IMG_COUNT 6
# define ENEMY_IMG_COUNT 4

typedef struct s_map
{
	char	*data;
	int		width;
	int		height;
	int		player_count;
	int		chest_count;
	int		door_count;
}	t_map;

typedef struct s_images
{
	void	*wall;
	void	*road;
	void	*door;
	void	*player[PLAYER_IMG_COUNT];
	void	*collectible[COLLECTIBLE_IMG_COUNT];
	void	*enemy[ENEMY_IMG_COUNT];
}	t_images;

typedef struct s_game_props
{
	void		*mlx;
	void		*win;
	int			collected_count;
	int			movement_count;
	void		*draw_functions[FUNCTION_TABLE_SIZE];
	t_images	imgs;
	t_map		map;
}	t_game_props;

enum e_object_name
{
	PLAYER = 'P',
	WALL = '1',
	ROAD = '0',
	DOOR = 'E',
	COLLECTIBLE = 'C',
	ENEMY = 'X'
};

#endif