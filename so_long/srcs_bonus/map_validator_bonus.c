/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:18:34 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/25 12:16:08 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "map_validator_bonus.h"
#include "ft_error_bonus.h"

static void	parse_map(t_map *map)
{
	char	*pdata;

	map->chest_count = 0;
	map->door_count = 0;
	map->player_count = 0;
	pdata = map->data;
	while (*pdata)
	{
		if (*pdata == 'P')
			map->player_count++;
		else if (*pdata == 'C')
			map->chest_count++;
		else if (*pdata == 'E')
			map->door_count++;
		pdata++;
	}
}

static void	check_wall(t_game_props *props)
{
	char	*pd;
	int		i;

	pd = props->map.data;
	i = 0;
	while (i < props->map.width)
		if (pd[i++] != '1')
			print_err(props, MAP_DATA_ERROR);
	i = 0;
	while (i < props->map.width)
		if (pd[i++ + props->map.width * (props->map.height - 1)] != '1')
			print_err(props, MAP_DATA_ERROR);
	i = 0;
	while (i < props->map.height)
	{
		if (pd[i * props->map.width] != '1')
			print_err(props, MAP_DATA_ERROR);
		if (pd[(i + 1) * props->map.width - 1] != '1')
			print_err(props, MAP_DATA_ERROR);
		i++;
	}
}

void	check_map_validation(t_game_props *props)
{
	parse_map(&props->map);
	if (props->map.chest_count < 1)
		print_err(props, MAP_DATA_ERROR);
	if (props->map.door_count != 1)
		print_err(props, MAP_DATA_ERROR);
	if (props->map.player_count != 1)
		print_err(props, MAP_DATA_ERROR);
	check_wall(props);
}
