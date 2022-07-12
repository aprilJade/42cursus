/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:04:07 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/09 17:20:10 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*handle;

	if (lst == NULL)
		return (NULL);
	new_lst = (t_list *)malloc(sizeof(t_list));
	if (new_lst == NULL)
		return (NULL);
	handle = new_lst;
	while (handle != NULL)
	{
		handle->content = f(lst->content);
		if (lst->next == NULL)
			break ;
		handle->next = (t_list *)malloc(sizeof(t_list));
		if (handle->next == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		handle = handle->next;
		lst = lst->next;
	}
	handle->next = NULL;
	return (new_lst);
}
