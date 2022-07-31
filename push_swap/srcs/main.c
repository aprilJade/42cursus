/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:16:32 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 12:17:00 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "props.h"
#include "err.h"

int main(int argc, char **argv)
{
	if (argc < 3)
		print_with_exit(INVALID_INPUT_ERR);
	t_props props;

	init_props(&props, argc, argv);	
	for (int i = 0; i < props.a->top + 1; i++)
		printf("%d\n", props.a->data[i]);
	exit(0);
}