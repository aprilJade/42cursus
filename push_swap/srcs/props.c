/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   props.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:17:02 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 12:37:28 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "props.h"
#include "input_parser.h"

void	init_props(t_props *props, int ac, char **av)
{
	int	*data;
	int	data_cnt;

	data_cnt = parse_argv(ac, av, &data);
	props->a = new_stack(data, data_cnt);
	props->b = new_stack(0, data_cnt);
}