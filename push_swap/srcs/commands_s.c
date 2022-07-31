/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:16:47 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 14:40:44 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include <unistd.h>

static void	basic_s(t_stack *stack)
{
	t_element	tmp[2];
	
	if (stack->top <= 0)
		return ;
	tmp[0] = pop(stack);
	tmp[1] = pop(stack);
	push(stack, tmp[0]);
	push(stack, tmp[1]);
}

void	sa(t_props *props)
{
	basic_s(props->a);
	write(1, "sa\n", 3);
}

void	sb(t_props *props)
{
	basic_s(props->b);
	write(1, "sb\n", 3);
}

void	ss(t_props *props)
{
	basic_s(props->a);
	basic_s(props->b);
	write(1, "ss\n", 3);
}