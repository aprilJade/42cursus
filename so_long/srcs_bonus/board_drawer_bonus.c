/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_drawer_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:57:42 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/25 18:26:48 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "board_drawer_bonus.h"
#include "mlx.h"
#include "string_utils_bonus.h"
#include "ft_error_bonus.h"
#include <stdlib.h>

static char	*gen_board_text(t_game_props *props)
{
	static char	*result;
	int			movement;
	int			movement_last_idx;

	if (result == NULL)
	{
		result = (char *)malloc(sizeof(char) * MOVEMENT_INFO_LEN + 1);
		if (result == NULL)
			print_err(props, MALLOC_ERROR);
		ft_strcpy(result, "Movement: ");
		ft_strcpy(result + 10, "0000");
		result[MOVEMENT_INFO_LEN + 1] = 0;
	}
	movement = props->movement_count;
	movement_last_idx = MOVEMENT_INFO_LEN - 1;
	while (movement > 0)
	{
		result[movement_last_idx--] = movement % 10 + '0';
		movement /= 10;
	}
	return (result);
}

void	draw_board(t_game_props *props)
{
	mlx_string_put(props->mlx, props->win, 5, 15, WHITE, gen_board_text(props));
}
