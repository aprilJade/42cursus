# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 15:40:10 by seonggyk          #+#    #+#              #
#    Updated: 2022/07/15 18:03:56 by seonggyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	cc

FLAG	=	-Wall -Wextra -Werror -g

INCLUDE	=	-Ift_printf_utils.h ft_printf.h

SRCS 	=	ft_printf_utils.c ft_printf.c print_address.c print_char.c \
			print_decimal.c print_hex.c print_percent_sign.c print_string.c \
			print_unsigned_decimal.c

#SRCS_BN	=

OBJS	=	$(SRCS:c=o)

#OBJS_BN	=	$(SRCS_BN:c=o)

OBJECTS	=	$(OBJS)

ifdef BONUS
	OBJECTS	+= $(OBJS_BN)
endif

all		:	$(NAME)

%.o	: %.c
	$(CC) $(FLAG) -c $< -o $@ 

$(NAME)	:	$(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus	:
	make BONUS=1
	
clean	:	
	rm -rf $(OBJS) $(OBJS_BN)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re bonus
