/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:01:14 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/05 22:13:18 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long	flag;
	long long	n;

	while (*str == " ")
		str++;
	if (*str == NULL)
		return (0);
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
	{
		flag = 1;
		str++;
	}
	n = 0;
	while (*str >= '0' && *str <= '9')
		n = n * 10 + (*str++ - '0');
	return ((int)(n * flag));
}
