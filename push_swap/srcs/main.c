#include <stdio.h>
#include <stdlib.h>
#include "props.h"
#include "err.h"

int main(int argc, char **argv)
{
	if (argc < 3)
		print_with_exit(INVALID_INPUT_ERR);
	t_props props;

	init_props(&props, argc, argv);	
	for (int i = 0; i < props.a->top + 1; i++)
		printf("%d\n", props.a->data[i]);
	exit(0);
}