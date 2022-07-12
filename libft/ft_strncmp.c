/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:12:10 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/08 19:34:46 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	const unsigned char	*p_str1;
	const unsigned char	*p_str2;

	p_str1 = (const unsigned char *)str1;
	p_str2 = (const unsigned char *)str2;
	while (n--)
	{
		if (*p_str1 != *p_str2)
			return (*p_str1 - *p_str2);
		if (!*p_str1 || !*p_str2)
			break ;
		p_str1++;
		p_str2++;
	}
	return (0);
}
