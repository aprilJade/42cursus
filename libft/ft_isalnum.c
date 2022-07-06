/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:25:09 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/04 15:26:11 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_isalpha(int c)
{
    int tmp = c ^ 0b01000000;

    if (c < 65)
        return (0);
        
    if (tmp > 64 && tmp < 123) {
        return c;
    }
    return (0);
}

static int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

int isalnum(int c)
{
    if (ft_isalpha(c) && ft_isdigit(c))
        return (c);
    return (0);
}
