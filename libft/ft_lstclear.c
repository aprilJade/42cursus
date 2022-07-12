/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:56:55 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/08 13:44:16 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*handle;
	t_list	*buf;

	handle = *lst;
	while (handle != NULL)
	{
		buf = handle->next;
		del(handle->content);
		free(handle);
		handle = buf;
	}
	*lst = NULL;
}
