/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_tools.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 12:27:23 by seonggyk          #+#    #+#             */
/*   Updated: 2022/05/01 12:27:36 by seonggyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMP_TOOLS_H
# define DUMP_TOOLS_H

int		check_read_error(char buf[16], char *file, int size, int fd);
int		check_size_limit(int fd, int size);
int		memory_compare(char s1[BUFFER_SIZE], char s2[BUFFER_SIZE]);
void	memory_copy(char dest[BUFFER_SIZE], char src[BUFFER_SIZE]);
int		check_overlap(char buf[16], char tmp[16], int *size, int *is_overlap);

#endif
