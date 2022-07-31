/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:17:12 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 12:17:12 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_H
# define ERR_H

enum e_err_code
{
	NO_ERR,
	MALLOC_ERR,
	INVALID_INPUT_ERR,
	SPLIT_ERR
};

void	print_with_exit(int err_code);

#endif