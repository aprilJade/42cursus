/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:01:00 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/23 16:26:27 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_MANAGER_H
# define GAME_MANAGER_H
# include "so_long.h"

typedef struct s_endgame_param
{
	t_game_props	*props;
	int				err_code;
}	t_endgame_param;

void	init_game(t_game_props *props, char *map_name);
int		end_game(t_endgame_param *param);

#endif