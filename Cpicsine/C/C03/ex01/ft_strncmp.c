/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:08:36 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/20 15:38:46 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				ret;

	i = 0;
	ret = 0;
	while (ret == 0 && i < n)
	{
		ret = s1[i] - s2[i];
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	if (ret > 0)
		ret = 1;
	else if (ret < 0)
		ret = -1;
	else
		ret = 0;
	return (ret);
}
