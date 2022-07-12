/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 04:18:51 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/10 14:59:26 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*h_dest;
	const unsigned char	*h_src;
	size_t				i;

	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	h_dest = (unsigned char *)dest;
	h_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		h_dest[i] = h_src[i];
		i++;
	}
	return (dest);
}
