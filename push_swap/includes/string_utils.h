/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:17:19 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/31 12:17:19 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTILS_H
# define STRING_UTILS_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648

int		ft_atoi(const char *s, int *out);
char	**ft_split(char *s, char c);

#endif