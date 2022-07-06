/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:12:10 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/04 23:14:17 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	strncmp(const char *str1, const char* str2, size_t n)
{
	size_t	i;

	i = 0;
	while (*str1 && *str2 && i++ < n)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

