/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:12:10 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/14 11:47:30 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	const unsigned char	*h_str1;
	const unsigned char	*h_str2;

	h_str1 = (const unsigned char *)str1;
	h_str2 = (const unsigned char *)str2;
	while (n--)
	{
		if (*h_str1 != *h_str2)
			return (*h_str1 - *h_str2);
		if (!*h_str1 || !*h_str2)
			break ;
		h_str1++;
		h_str2++;
	}
	return (0);
}
