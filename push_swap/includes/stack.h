#ifndef STACK_H
# define STACK_H
# define NULL 0

typedef struct s_stack
{
	int		top;
	int		*data;
}	t_stack;

t_stack	*new_stack(int *data, int stack_size);
int		pop(t_stack *stack);
void	push(t_stack *stack, int value);


#endif