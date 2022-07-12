/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:47:51 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/04 16:57:57 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*handle;

	handle = (unsigned char *)s;
	i = 0;
	while (i < n)
		handle[i++] = (unsigned char)c;
	return (handle);
}
