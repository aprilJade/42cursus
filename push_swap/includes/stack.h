/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:17:16 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 12:17:17 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	int		top;
	int		*data;
}	t_stack;

t_stack	*new_stack(int *data, int stack_size);
int		pop(t_stack *stack);
void	push(t_stack *stack, int value);


#endif