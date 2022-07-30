#include "stack.h"
#include <stdlib.h>

t_stack	*new_stack(int *data, int stack_size)
{
	t_stack	*ret;

	ret = (t_stack *)malloc(sizeof(t_stack));
	if (ret == NULL)
		exit(1);
	if (data)
	{
		ret->top = stack_size - 1;
		ret->data = data;
	}
	else
	{
		ret->data = (int *)malloc(sizeof(int) * stack_size);
		if (ret->data == NULL)
			exit(1);
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