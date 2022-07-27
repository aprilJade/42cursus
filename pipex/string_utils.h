/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:34:15 by seonggyk          #+#    #+#             */
/*   Updated: 2022/07/26 17:09:38 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTILS_H
# define STRING_UTILS_H

int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strchr(char *s, char c);
void	ft_strncpy(char *dst, char *src, int n);
int		ft_strlen(char *s);
char	*ft_strndup(char *src, int n);
void	ft_strcpy(char *s, char *d);
char	**ft_split(char const *s, char c);

#endif