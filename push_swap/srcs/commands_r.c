/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:16:42 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 14:36:19 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include <unistd.h>

static void	basic_r(t_stack *stack)
{
	t_element	value;
	int			i;

	if (stack->top <= 0)
		return ;
	value = stack->data[stack->top];
	i = stack->top - 1;
	while (i >= 0)
	{
		stack->data[i + 1] = stack->data[i];
		i++;
	}
	stack->data[0] = value;
}

void	ra(t_props *props)
{
	basic_r(props->a);
	write(1, "ra\n", 3);
}

void	rb(t_props *props)
{
	basic_r(props->b);
	write(1, "rb\n", 3);
}

void	rr(t_props *props)
{
	basic_r(props->a);
	basic_r(props->b);
	write(1, "rr\n", 3);
}