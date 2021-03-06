/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:16:50 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 12:16:51 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err.h"
#include <unistd.h>
#include <stdlib.h>

void	print_with_exit(int err_code)
{
	if (err_code == MALLOC_ERR)
		write(2, "Malloc Error\n", 13);
	else if (err_code == SPLIT_ERR)
		write(2, "Split Error\n", 12);
	else if (err_code == INVALID_INPUT_ERR)
		write(2, "Error\n", 6);
	exit(err_code);
}