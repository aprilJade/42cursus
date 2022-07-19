# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 15:40:10 by seonggyk          #+#    #+#              #
#    Updated: 2022/07/18 16:15:19 by seonggyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	cc

FLAG	=	-Wall -Wextra -Werror -g

INCLUDE	=	-Ift_printf_utils.h ft_printf.h

SRCS 	=	ft_printf_utils.c ft_printf.c print_address.c print_char.c \
			print_decimal.c print_hex.c print_percent_sign.c print_string.c \
			print_unsigned_decimal.c

OBJS	=	$(SRCS:c=o)

OBJECTS	=	$(OBJS)

all		:	$(NAME)

%.o	: %.c
	$(CC) $(FLAG) -c $< -o $@ 

$(NAME)	:	$(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean	:	
	rm -rf $(OBJS)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
