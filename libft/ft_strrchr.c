/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:09:35 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/13 18:17:29 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*ps;

	ps = s;
	while (*ps)
		ps++;
	if (c == 0)
		return ((char *)ps);
	while (s != ps--)
		if (*ps == (char)c)
			return ((char *)ps);
	return (0);
}
