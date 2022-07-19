/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 08:44:39 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/21 18:35:54 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	char	*s;

	s = str;
	while (*str++)
		;
	return (str - s - 1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		len;
	char	*f;

	f = to_find;
	if (ft_strlen(to_find) == 0)
		return (str);
	while (*str != '\0')
	{
		to_find = f;
		while (*str != *to_find && *str != '\0')
			str++;
		len = 0;
		while (*str == *to_find && *str != '\0')
		{
			len++;
			str++;
			to_find++;
			if (*to_find == '\0')
				return (str - len);
		}
	}
	return (0);
}
