/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:25:23 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/14 11:43:49 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *l, const void *r, size_t n)
{
	const unsigned char	*hl;
	const unsigned char	*hr;

	hl = (const unsigned char *)l;
	hr = (const unsigned char *)r;
	while (n--)
	{
		if (*hl != *hr)
			return (*hl - *hr);
		hl++;
		hr++;
	}
	return (0);
}
