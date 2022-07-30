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