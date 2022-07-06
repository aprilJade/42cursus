/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:25:23 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/04 23:27:44 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *l, const void *r, size_t n)
{
	size_t		i;
	const char	*pl;
	const char	*pr;

	pl = l;
	pr = r;
	i = 0;
	while (*pl && *pr && i++ < n)
	{
		if (*pl != *pr)
			return (*pl - *pr);
		pl++;
		pr++;
	}
	return (0);
}
