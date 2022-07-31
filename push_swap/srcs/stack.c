/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:17:04 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 13:56:43 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "err.h"
#include <stdlib.h>

t_stack	*new_stack(int *data, int stack_size)
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
		ret->data = (int *)malloc(sizeof(int) * stack_size);
		if (ret->data == 0)
			print_with_exit(MALLOC_ERR);
		ret->top = -1;
	}
	return (ret);
}

int		pop(t_stack *stack)
{
	return (stack->data[stack->top--]);
}

void		push(t_stack *stack, int value)
{
	stack->data[++stack->top] = value;
}

int		check_duplication(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->data[i] <= stack->data[i + 1])
			return (1);
		i++;
	}
	return (0);
}