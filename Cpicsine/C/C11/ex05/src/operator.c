/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:02:40 by seonggyk          #+#    #+#             */
/*   Updated: 2022/05/02 13:17:47 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operator.h"

int	add(int a, int b)
{
	return (a + b);
}

int	minus(int a, int b)
{
	return (a - b);
}

int	divide(int a, int b)
{
	return (a / b);
}

int	modular(int a, int b)
{
	return (a % b);
}

int	multiply(int a, int b)
{
	return (a * b);
}
