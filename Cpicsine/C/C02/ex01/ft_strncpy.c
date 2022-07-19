/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:29:05 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/21 08:21:20 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && *src != '\0')
		dest[i++] = *src++;
	while (i < n)
		dest[i++] = 0;
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[12];
	memset(buf, 0, 12);
	ft_strncpy(buf, "aeifjlsae", 3);
	printf("%s\n",buf);
	memset(buf, 0, 12);
	ft_strncpy(buf, "aeifjlsae", 0);
	printf("%s\n",buf);
	memset(buf, 0, 12);
	ft_strncpy(buf, "aeifjlsae", 5);
	printf("%s\n",buf);
	memset(buf, 0, 12);
	ft_strncpy(buf, "aeifjlsae", 10);
	printf("%s\n",buf);
	memset(buf, 0, 12);

	strncpy(buf, "aeifjlsae", 3);
	printf("%s\n",buf);
	memset(buf, 0, 12);
	strncpy(buf, "aeifjlsae", 0);
	printf("%s\n",buf);
	memset(buf, 0, 12);
	strncpy(buf, "aeifjlsae", 5);
	printf("%s\n",buf);
	memset(buf, 0, 12);
	strncpy(buf, "aeifjlsae", 10);
	printf("%s\n",buf);
	memset(buf, 0, 12);
}
*/
