/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:40:08 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/25 17:59:31 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_BONUS_H
# define FT_ERROR_BONUS_H
# include "so_long_bonus.h"

enum e_error_code
{
	ARG_ERROR = -100,
	FILE_ERROR,
	READ_ERROR,
	MALLOC_ERROR,
	MAP_NAME_ERROR,
	MAP_DATA_ERROR,
	NO_ERROR = 0
};

void	print_err(t_game_props *props, int error_code);

#endif