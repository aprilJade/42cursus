#ifndef PROPS_H
# define PROPS_H
# include "stack.h"

typedef struct s_props
{
	t_stack	*a;
	t_stack	*b;
}	t_props;

void	init_props(t_props *props, int ac, char **av);

#endif