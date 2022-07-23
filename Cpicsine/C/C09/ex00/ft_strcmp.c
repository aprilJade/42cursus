/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:59:29 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/28 11:24:00 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	ret;

	ret = 0;
	while (ret == 0)
	{
		ret = *s1 - *s2;
		if (*s1 == 0 || *s2 == 0)
			return (ret);
		s1++;
		s2++;
	}
	return (ret);
}