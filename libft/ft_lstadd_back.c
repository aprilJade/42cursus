/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:49:23 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/08 19:46:55 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*handle;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	handle = *lst;
	while (handle->next != NULL)
		handle = handle->next;
	handle->next = new;
	new->next = NULL;
}
