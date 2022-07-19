/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:29:17 by seonggyk          #+#    #+#             */
/*   Updated: 2022/05/02 13:21:25 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operate.h"
#include "../includes/operator.h"
#include <unistd.h>
#define OP_CNT 5
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 8

enum e_argv
{
	program_name,
	first_number,
	operator,
	second_number
};

void	make_op_arr(void **ops)
{
	ops[0] = (void *)add;
	ops[1] = (void *)minus;
	ops[2] = (void *)divide;
	ops[3] = (void *)modular;
	ops[4] = (void *)multiply;
}

void	make_str_operators(char str[4])
{
	str[0] = '+';
	str[1] = '-';
	str[2] = '/';
	str[3] = '%';
	str[4] = '*';
}

int	main(int argc, char **argv)
{
	void	*op;
	int		i;
	void	*ops[OP_CNT];
	char	str_operators[OP_CNT];

	if (argc != 4)
		return (EXIT_FAILURE);
	make_op_arr(ops);
	make_str_operators(str_operators);
	i = 0;
	op = 0;
	while (i < OP_CNT)
	{
		if (str_operators[i] == argv[operator][0] && argv[operator][1] == 0)
			op = ops[i];
		i++;
	}
	if (op == 0)
	{
		write(1, "0\n", 2);
		return (-1);
	}
	operate(argv[first_number], argv[second_number], op);
	return (EXIT_SUCCESS);
}
