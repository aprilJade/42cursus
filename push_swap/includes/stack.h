/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:17:16 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 16:57:00 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_element
{
	int	value;
	int	ranking;
}	t_element;

typedef struct s_stack
{
	int			top;
	t_element	*data;
}	t_stack;

t_stack		*new_stack(t_element *data, int stack_size);
t_element	pop(t_stack *stack);
void		push(t_stack *stack, t_element value);

#endif