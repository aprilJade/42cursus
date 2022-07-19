/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 11:23:13 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/21 08:25:05 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const char	*g_hex_arr = "0123456789abcdef";

void	print_remain_space(int len)
{
	int	i;

	i = 0;
	while (i < 40 - len * 2 - len / 2 - len % 2 + 1)
	{
		write(1, " ", 1);
		i++;
	}
}

void	print_address(void *addr)
{
	int				i;
	unsigned char	*ptr;

	ptr = (unsigned char *)&addr;
	i = 7;
	while (i >= 0)
	{
		write(1, &g_hex_arr[ptr[i] / 16], 1);
		write(1, &g_hex_arr[ptr[i--] % 16], 1);
	}
	write(1, ": ", 2);
}

void	print_value_in_hex(void *addr, int size)
{
	unsigned char	*ptr;
	int				i;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < 16 && size-- > 0)
	{
		write(1, &g_hex_arr[ptr[i] / 16], 1);
		write(1, &g_hex_arr[ptr[i] % 16], 1);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	print_remain_space(i);
}

void	print_value_in_char(void *addr, int size)
{
	unsigned char	*ptr;
	int				i;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < 16 && size-- > 0)
	{
		if (ptr[i] < 32 || ptr[i] > 126)
			write(1, ".", 1);
		else
			write(1, &ptr[i], 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void			*ret;
	unsigned char	*str;
	int				cnt;

	cnt = (int)size;
	ret = addr;
	while (cnt > 0)
	{
		str = (unsigned char *)addr;
		print_address(addr);
		print_value_in_hex(addr, cnt);
		print_value_in_char(addr, cnt);
		addr += 16;
		cnt -= 16;
		write(1, "\n", 1);
	}
	return (ret);
}
/*
int	main(void)
{
	char string[94] = {0x42, 0x6f, 0x6e, 0x6a, 0x6f, 0x75, 0x72, 0x20,
	 			0x6c, 0x65, 0x73, 0x20, 0x61, 0x6d, 0x69, 0x6e,
				0x63, 0x68, 0x65, 0x73, 0x09, 0x0a, 0x09, 0x63,
				0x20, 0x20, 0x65, 0x73, 0x74, 0x20, 0x66, 0x6f,
				0x75, 0x09, 0x74, 0x6f, 0x75, 0x74, 0x09, 0x63,
				0x65, 0x20, 0x71, 0x75, 0x20, 0x6f, 0x6e, 0x20,
				0x70, 0x65, 0x75, 0x74, 0x20, 0x66, 0x61, 0x69,
				0x72, 0x65, 0x20, 0x61, 0x76, 0x65, 0x63, 0x09,
				0x0a, 0x09, 0x70, 0x72, 0x69, 0x6e, 0x74, 0x5f,
				0x6d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 0x0a, 0x0a,
				0x0a, 0x09, 0x6c, 0x6f, 0x6c, 0x2e, 0x6c, 0x6f,
				0x6c, 0x0a, 0x20 
	};
	ft_print_memory(string, 92);
}
*/
