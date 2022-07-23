/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:54:41 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/23 15:45:52 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_error.h"
#include "input_handler.h"
#include "so_long.h"
#include "mlx.h"
#include "game_manager.h"
#include "string_utils.h"

static int	check_map_name_validation(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	while (len--)
		if (map_name[len] == '.')
			break ;
	if (len == -1)
		len = 0;
	return (ft_strcmp(&map_name[len], ".ber") == 0);
}

int	main(int argc, char **argv)
{
	t_game_props	props;

	if (argc != 2)
		print_err(&props, ARG_ERROR);
	ft_memset((void *)&props, 0, sizeof(t_game_props));
	if (!check_map_name_validation(argv[1]))
		print_err(&props, MAP_NAME_ERROR);
	init_game(&props, argv[1]);
	mlx_hook(props.win, RELEASE_KEY_EVENT, 0, &keyboard_input_listener, &props);
	mlx_hook(props.win, WIN_DESTROY_EVENT, 0, end_game, &props);
	mlx_loop(props.mlx);
	return (0);
}