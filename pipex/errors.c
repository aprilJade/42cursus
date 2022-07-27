/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:34:21 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/26 17:19:02 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "string_utils.h"
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

void	print_err_and_exit(char *custom_msg)
{
	if (custom_msg)
		write(STDERR_FILENO, custom_msg, ft_strlen(custom_msg));
	else
		perror("pipex");
	exit(EXIT_FAILURE);
}