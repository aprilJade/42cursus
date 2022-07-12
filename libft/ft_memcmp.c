/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:25:23 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/08 19:04:55 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *l, const void *r, size_t n)
{
	size_t				i;
	const unsigned char	*pl;
	const unsigned char	*pr;

	pl = (const unsigned char *)l;
	pr = (const unsigned char *)r;
	i = 0;
	while (i++ < n)
	{
		if (*pl != *pr)
			return (*pl - *pr);
		pl++;
		pr++;
	}
	return (0);
}
