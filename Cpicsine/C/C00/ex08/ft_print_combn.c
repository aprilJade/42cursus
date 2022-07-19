/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:59:15 by seonggyk          #+#    #+#             */
/*   Updated: 2022/04/16 21:39:06 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int n, char *numbers)
{
	int		i;

	i = 0;
	while (i < n)
		ft_putchar(numbers[i++] + 48);
	
}

void	ft_increment_numbers(int n, char *numbers)
{
	int		i;
	int		max;
	numbers[3] == *(numbers + 3)
	i = n - 1;
	max = 9;
	while (numbers[i] == max)
	{
		i--;
		max--;
	}
	numbers[i] += 1;
	while (i < n - 1)
	{
		numbers[i + 1] = numbers[i] + 1;
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	numbers[11];
	int		i;

	i = 0;
	while (i < n)
	{
		numbers[i] = i;
		i++;
	}
	numbers[i] = '\0';
	ft_print_number(n, numbers);
	while (numbers[0] < 10 - n)
	{
		if (numbers[n - 1] < 9)
			numbers[n - 1]++;
		else
			ft_increment_numbers(n, numbers);
		write(1, ", ", 2);
		ft_print_number(n, numbers);
	}
}
