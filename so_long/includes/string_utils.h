/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:09:17 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/23 15:41:03 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTILS_H
# define STRING_UTILS_H

void	ft_putstr(char *s);
int		ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
void	ft_strcpy(char *dst, char *src);
void	ft_memset(void *dst, int value, int size);

#endif