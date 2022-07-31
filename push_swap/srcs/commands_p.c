/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:16:40 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 12:16:41 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include <unistd.h>

static void	basic_p(t_stack *dst, t_stack *src)
{
	if (src->top <= 0)
		return ;
	push(dst, pop(src));
}

void	pa(t_props *props)
{
	basic_p(props->b, props->a);
	write(1, "pa\n", 3);
}

void	pb(t_props *props)
{
	basic_p(props->a, props->b);
	write(1, "pb\n", 3);
}