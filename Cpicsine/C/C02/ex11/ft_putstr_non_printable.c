/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                            :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 08:03:22 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/20 20:56:35 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

const char	*g_hex_arr = "0123456789abcdef";

bool	is_printable(unsigned char c)
{
	if (c >= 32 && c <= 126)
		return (true);
	else
		return (false);
}

void	putchar_in_hex(unsigned char c)
{
	write(1, "\\", 1);
	write(1, &g_hex_arr[c / 16], 1);
	write(1, &g_hex_arr[c % 16], 1);
}	

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*str_buf;

	str_buf = (unsigned char *)str;
	while (*str_buf != '\0')
	{
		if (is_printable(*str_buf) == true)
			write(1, str_buf++, 1);
		else
			putchar_in_hex(*str_buf++);
	}
}
/*
int main(void)
{
	//char buf[128] = "Coucou\ntu vas bien ?";
	char *strs[10];
    strs[0] = "Hello, World!";
    strs[1] = "HELLO";
    strs[2] = "c Is tHE bEst";
    strs[3] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    strs[4] = "\0empty?\0";
    strs[5] = "before\0after";
    strs[6] = "";
    strs[7] = "***...***";
    strs[8] = "0123456789-";
    strs[9] = "  \t.\e.abc\adef\b\x18yes\v";
	ft_putstr_non_printable("\x18");
}
*/
