/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_drawer_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:56:59 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/25 18:37:06 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_DRAWER_BONUS_H
# define BOARD_DRAWER_BONUS_H
# include "so_long_bonus.h"
# define WHITE 0xffffff
# define BLACK 0x000000
# define MOVEMENT_INFO_LEN 14

void	draw_board(t_game_props *props);

#endif