/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:09:35 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/04 23:11:44 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strrchr(const char *s, int c)
{
	const char	*ps;

	ps = s;
	while (*ps)
		ps++;
	while (s != ps)
	{
		if (*ps == c)
			return (ps);
		ps--;
	}
	return (0);
}
