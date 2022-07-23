/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:41:56 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/23 16:20:18 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "string_utils.h"
#include "game_manager.h"

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
