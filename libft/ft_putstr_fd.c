/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:36:43 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/08 20:08:54 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_strlen(char *s)
{
	char	*str;

	str = s;
	while (*s)
		s++;
	return (s - str);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	len;
	int	sum;
	int	result;

	if (s == NULL || fd < 0)
		return ;
	len = ft_strlen(s);
	result = 0;
	sum = 0;
	while (sum != len)
	{
		s += sum;
		len -= sum;
		result = write(fd, s, len);
		sum += result;
	}
}
