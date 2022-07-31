/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:17:04 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 16:56:45 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "err.h"
#include <stdlib.h>

t_stack	*new_stack(t_element *data, int stack_size)
{
	t_stack	*ret;

	ret = (t_stack *)malloc(sizeof(t_stack));
	if (ret == 0)
		print_with_exit(MALLOC_ERR);
	if (data)
	{
		ret->top = stack_size - 1;
		ret->data = data;
	}
	else
	{
		ret->data = (t_element *)malloc(sizeof(t_element) * stack_size);
		if (ret->data == 0)
			print_with_exit(MALLOC_ERR);
		ret->top = -1;
	}
	return (ret);
}

t_element	pop(t_stack *stack)
{
	return (stack->data[stack->top--]);
}

void	push(t_stack *stack, t_element value)
{
	stack->data[++stack->top] = value;
}
