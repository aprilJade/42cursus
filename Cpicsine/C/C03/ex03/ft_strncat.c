/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 08:36:09 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/20 13:44:17 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*ret;

	i = 0;
	ret = dest;
	while (*dest != '\0')
		dest++;
	while (src[i] != '\0' && i < nb)
		*dest++ = src[i++];
	*dest = '\0';
	return (ret);
}
