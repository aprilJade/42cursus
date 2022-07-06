/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 04:18:51 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/04 04:20:46 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*hDest;
	unsigned char	*hSrc;
	size_t			i;

	hDest = dest;
	hSrc = src;
	i = 0;
	while (i < n)
		hDest[i++] = hSrc[i];
	return (dest);
}
