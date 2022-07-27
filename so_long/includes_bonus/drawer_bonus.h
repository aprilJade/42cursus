/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:21:46 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/25 17:59:28 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWER_BONUS_H
# define DRAWER_BONUS_H
# include "so_long_bonus.h"

void	draw_wall(t_game_props *props, int x, int y, int cur_frame);
void	draw_door(t_game_props *props, int x, int y, int cur_frame);
void	draw_road(t_game_props *props, int x, int y, int cur_frame);
void	draw_player(t_game_props *props, int x, int y, int cur_frame);
void	draw_collectible(t_game_props *props, int x, int y, int cur_frame);
void	draw_enemy(t_game_props *props, int x, int y, int cur_frame);

#endif