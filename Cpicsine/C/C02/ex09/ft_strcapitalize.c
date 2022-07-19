/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 09:20:07 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/21 08:28:36 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#define IS_NUMERIC 0
#define IS_LOWER_ALPHA 1
#define IS_UPPER_ALPHA 2
#define IS_NOT_NUMERIC_ALPHA -1

int	check_character(char c)
{
	if (c >= 'a' && c <= 'z')
		return (IS_LOWER_ALPHA);
	else if (c >= 'A' && c <= 'Z')
		return (IS_UPPER_ALPHA);
	else if (c >= '0' && c <= '9')
		return (IS_NUMERIC);
	else
		return (IS_NOT_NUMERIC_ALPHA);
}

char	*ft_strcapitalize(char *str)
{
	char	*ret;

	ret = str;
	while (*str != '\0')
	{
		while (check_character(*str) == IS_NOT_NUMERIC_ALPHA && *str++ != '\0')
			;
		if (check_character(*str) == IS_LOWER_ALPHA)
			*str ^= 0b00100000;
		str++;
		while (check_character(*str) >= IS_NUMERIC && *str != '\0')
		{
			if (check_character(*str) == IS_UPPER_ALPHA)
				*str ^= 0b00100000;
			str++;
		}
	}
	return (ret);
}
