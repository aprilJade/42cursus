/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:16:32 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 13:57:50 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "props.h"
#include "err.h"
#include "solver.h"

int main(int argc, char **argv)
{
	if (argc < 3)
		print_with_exit(INVALID_INPUT_ERR);
	t_props props;

	init_props(&props, argc, argv);	
	bubble_sort(props.a->data, props.a->top + 1);
	if (check_duplication(props.a))
		print_with_exit(INVALID_INPUT_ERR);
	for (int i = 0; i < props.a->top + 1; i++)
		printf("%d\n", props.a->data[i]);
	exit(0);
}