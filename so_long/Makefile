# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 12:26:18 by seonggyk          #+#    #+#              #
#    Updated: 2022/07/23 15:09:54 by seonggyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CFLAG		=	-Wall -Wextra -Werror
INCLUDES	=	-Imlx -Iincludes
LIB			=	-Lmlx -lmlx
FRAMEWORK	=	-framework OpenGL -framework AppKit
SRCS		=	./srcs/drawer.c ./srcs/ft_error.c ./srcs/game_manager.c \
				./srcs/main.c ./srcs/map_validator.c ./srcs/string_utils.c \
				./srcs/map_reader.c ./srcs/input_handler.c ./srcs/map_drawer.c
OBJS		=	$(SRCS:c=o)

ifdef DEBUG
	CFLAG += -g -fsanitize=address
endif

%.o:	%.c
	cc $(CFLAG) $(INCLUDES) -c $< -o $@ 

$(NAME):$(OBJS)
	cc $(CFLAG) $(LIB) $(FRAMEWORK) $(INCLUDES) -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re:
	make fclean
	make all

debug:
	make fclean
	make DEBUG=1 all
.PHONY:all clean fclean re debug
