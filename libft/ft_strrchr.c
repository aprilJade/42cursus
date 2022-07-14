/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:09:35 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/14 11:47:52 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*hs;

	hs = s;
	while (*hs)
		hs++;
	if (c == 0)
		return ((char *)hs);
	while (s != hs--)
		if (*hs == (char)c)
			return ((char *)hs);
	return (0);
}
