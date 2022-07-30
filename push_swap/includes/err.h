#ifndef ERR_H
# define ERR_H

enum e_err_code
{
	NO_ERR,
	MALLOC_ERR,
	INVALID_INPUT_ERR,
	SPLIT_ERR
};

void	print_with_exit(int err_code);

#endif