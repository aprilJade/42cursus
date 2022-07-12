# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonggyk <seonggyk@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 15:40:10 by seonggyk          #+#    #+#              #
#    Updated: 2022/07/12 15:58:36 by seonggyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

LIB		=	ar -rcs

CC		=	cc

FLAG	=	-Wall -Wextra -Werror

INCLUDE	=	-Ilibft.h

SRCS 	= ft_memset.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c ft_atoi.c \
			ft_strncmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
			ft_strrchr.c ft_substr.c ft_strnstr.c ft_calloc.c ft_strdup.c \
			ft_strjoin.c ft_itoa.c ft_strtrim.c ft_split.c ft_bzero.c ft_memcpy.c \
			ft_memmove.c ft_memchr.c ft_memcmp.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c

SRCS_BN	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
			ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS	=	$(SRCS:c=o)

OBJS_BN	=	$(SRCS_BN:c=o)

OBJECTS	=	$(OBJS)

ifdef BONUS
	OBJECTS	+= $(OBJS_BN)
endif

all		:	$(NAME)

%.o	: %.c
	$(CC) $(FLAG) -c $< -o $@ $(INCLUDE)

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
