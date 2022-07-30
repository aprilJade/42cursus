#include "stack.h"

t_stack	*new_stack(int *data, int stack_size)
{
	t_stack	*ret;

	ret = (t_stack *)malloc(sizeof(t_stack));
	if (ret == NULL)
		return (NULL);
	ret->size = stack_size;
	ret->top = -1;
	ret->data = NULL;
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