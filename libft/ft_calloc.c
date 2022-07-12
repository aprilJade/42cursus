/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:15:21 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/08 10:42:49 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t num, size_t size)
{
	char	*ret;
	size_t	i;

	ret = (char *)malloc(num * size);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < num * size)
		ret[i++] = 0;
	return ((void *)ret);
}
