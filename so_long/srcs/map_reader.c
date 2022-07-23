/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:50:11 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/23 16:05:14 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_error.h"
#include "map_reader.h"
#include "string_utils.h"

static int	get_map_width(char *data)
{
	char	*pd;

	pd = data;
	while (*pd)
	{
		if (*pd == '\n')
			return (pd - data);
		pd++;
	}
	return (MAP_DATA_ERROR);
}

static int	get_map_height(char *data, int width)
{
	int	height;
	char	*pd;

	pd = data;
	while (*pd)
		pd++;
	height = 0;
	while (1)
	{
		data += width;
		if (data > pd)
			return (MAP_DATA_ERROR);
		if (*data != '\n' && *data != '\0')
			return (MAP_DATA_ERROR);
		height++;
		if (*data == '\0')
			break ;
		data++;
	}
	return (height);
}

static void	prep_map_data(t_game_props* props, char *data)
{
	props->map.width = get_map_width(data);
	if (props->map.width == MAP_DATA_ERROR)
		print_err(props, MAP_DATA_ERROR);
	props->map.height = get_map_height(data, props->map.width);
	if (props->map.height == MAP_DATA_ERROR)
		print_err(props, MAP_DATA_ERROR);
	while (1)
	{
		while (*data != '\n' && *data != '\0')
			data++;
		if (*data == '\0')
			break ;
		ft_strcpy(data, data + 1);
	}
}

void	read_map(t_game_props *props, char *map_name)
{
	int		fd;
	char	buf[BUFFER_SIZE];
	int		size;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		print_err(props, FILE_ERROR);
	size = read(fd, buf, BUFFER_SIZE);
	if (size <= 0)
		print_err(props, READ_ERROR);
	buf[size] = 0;
	close(fd);
	prep_map_data(props, buf);
	props->map.data = (char *)malloc(sizeof(char) * props->map.width * props->map.height + 1);
	if (props->map.data == NULL)
		print_err(props, MALLOC_ERROR);
	ft_strcpy(props->map.data, buf);
}

