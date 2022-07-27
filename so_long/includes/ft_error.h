/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:40:08 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/23 16:25:00 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H
# include "so_long.h"

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