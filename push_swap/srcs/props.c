#include "props.h"
#include "argv_parser.h"

void	init_props(t_props *props, int ac, char **av)
{
	int	*data;
	int	data_cnt;

	data_cnt = parse_argv(ac, av, &data);
	props->a = new_stack(data, data_cnt);
	props->b = new_stack(0, data_cnt);
}