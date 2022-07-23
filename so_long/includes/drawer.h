/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:21:46 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/23 16:24:52 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWER_H
# define DRAWER_H
# include "so_long.h"

void	draw_player(t_game_props *props, int x, int y);
void	draw_wall(t_game_props *props, int x, int y);
void	draw_grass(t_game_props *props, int x, int y);
void	draw_chest(t_game_props *props, int x, int y);
void	draw_door(t_game_props *props, int x, int y);

#endif