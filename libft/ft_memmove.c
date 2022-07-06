/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 05:37:04 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/04 05:46:02 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	move_from_front(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		dest[i++] = src[i];
}

static void move_from_back(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = n - 1;
	while (i >= 0)
		dest[i] = src[i--];
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	flag;

	if (dest == src)
		return (dest);
	if (dest > src)
		move_from_back(dest, src, n);
	else
		move_from_front(dest, src, n);
	return (dest);
}
