#include "commands.h"

static int	basic_rr(t_stack *stack)
{
	int	value;
	int	i;

	if (stack->top <= 0)
		return ;
	value = stack->data[0];
	i = 1;
	while (i <= stack->top)
	{
		stack->data[i - 1] = stack->data[i];
		i++;
	}
	stack->data[stack->top] = value;
}

void	rra(t_props *props)
{
	basic_rr(props->a);
	write(1, "rra\n", 4);
}

void	rrb(t_props *props)
{
	basic_rr(props->b);
	write(1, "rrb\n", 4);
}

void	rrr(t_props *props)
{
	basic_rr(props->a); 
	basic_rr(props->b);
	write(1, "rrr\n", 4);
}