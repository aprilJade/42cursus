#include "commands.h"
#include <unistd.h>

static void	basic_s(t_stack *stack)
{
	int	tmp[2];
	
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