/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   props.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:17:14 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 17:00:02 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROPS_H
# define PROPS_H
# include "stack.h"

typedef struct s_props
{
	t_stack	*a;
	t_stack	*b;
	int		*sorted_data;
}	t_props;

void	init_props(t_props *props, int ac, char **av);

#endif