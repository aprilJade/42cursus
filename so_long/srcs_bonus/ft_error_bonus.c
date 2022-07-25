/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:41:56 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/25 12:16:19 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error_bonus.h"
#include "string_utils_bonus.h"
#include "game_manager_bonus.h"

void	print_err(t_game_props *props, int error_code)
{
	t_endgame_param	param;

	if (error_code == ARG_ERROR)
		ft_putstr("Error\nInvalid argument count\n");
	else if (error_code == FILE_ERROR)
		ft_putstr("Error\nFile error\n");
	else if (error_code == READ_ERROR)
		ft_putstr("Error\nRead error\n");
	else if (error_code == MALLOC_ERROR)
		ft_putstr("Error\nmalloc error\n");
	else if (error_code == MAP_NAME_ERROR)
		ft_putstr("Error\nInvalid map name\n");
	else if (error_code == MAP_DATA_ERROR)
		ft_putstr("Error\nInvalid map\n");
	param.props = props;
	param.err_code = error_code;
	end_game(&param);
}
