/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:37:26 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/27 13:37:26 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

void	ft_strcpy(char *d, char *s)
{
	while (*s)
		*d++ = *s++;
	*d = 0;
}

int	ft_strlen(char *str)
{
	char	*s;

	s = str;
	while (*str)
		str++;
	return (str - s);
}

int	set_stock_str(int size, char *str, struct s_stock_str *stock_str)
{
	stock_str->size = size;
	stock_str->str = str;
	stock_str->copy = 0;
	if (str != 0)
	{
		stock_str->copy = (char *)malloc(sizeof(char) + size + 1);
		if (stock_str->copy == NULL)
			return (-1);
		ft_strcpy(stock_str->copy, str);
	}
	return (0);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*stock;
	int					i;

	stock = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (stock == NULL)
		return (NULL);
	if (set_stock_str(0, 0, &stock[ac]) == -1)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (set_stock_str(ft_strlen(av[i]), av[i], &stock[i]) == -1)
			return (NULL);
		i++;
	}
	return (stock);
}
