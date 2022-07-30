#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	int		top;
	int		*data;
	int		size;
}	t_stack;

t_stack	*new_stack(int *data, int stack_size);
int		pop(t_stack *stack);
int		push(t_stack *stack, int value);


#endif