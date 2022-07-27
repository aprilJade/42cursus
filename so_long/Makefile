# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 12:26:18 by seonggyk          #+#    #+#              #
#    Updated: 2022/07/26 11:57:33 by seonggyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
BONUS_NAME		=	so_long_bonus
CFLAG			=	-Wall -Wextra -Werror
INCLUDES		=	-I./mlx/ -I./includes/
BONUS_INCLUDES	=	-I./mlx/ -I./includes_bonus/
LIB				=	-Lmlx -lmlx
FRAMEWORK		=	-framework OpenGL -framework AppKit
SRC				=	drawer.c ft_error.c game_manager.c \
					main.c map_validator.c string_utils.c \
					map_reader.c input_handler.c map_drawer.c
BONUS_SRC		=	drawer_bonus.c ft_error_bonus.c game_manager_bonus.c \
					main_bonus.c map_validator_bonus.c string_utils_bonus.c \
					map_reader_bonus.c input_handler_bonus.c map_drawer_bonus.c \
					renderer_bonus.c image_reader_bonus.c drawer2_bonus.c \
					board_drawer_bonus.c image_remover_bonus.c
SRCS			=	$(addprefix ./srcs/, $(SRC))
OBJS			=	$(SRCS:.c=.o)
BONUS_SRCS		=	$(addprefix ./srcs_bonus/, $(BONUS_SRC))
BONUS_OBJS		=	$(BONUS_SRCS:.c=.o)

ifdef DEBUG
	CFLAG += -g -fsanitize=address
endif

%.o: %.c
	cc $(CFLAG) $(INCLUDES) $(BONUS_INCLUDES) -c $< -o $@ 

$(NAME): $(OBJS)
	make -C ./mlx
	cc $(CFLAG) $(LIB) $(FRAMEWORK) $(INCLUDES) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

re:
	make fclean
	make all

debug:
	make fclean
	make DEBUG=1 all

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	make -C ./mlx
	cc $(CFLAG) $(LIB) $(FRAMEWORK) $(BONUS_INCLUDES) -o $(BONUS_NAME) $(BONUS_OBJS)

.PHONY: all clean fclean re debug bonus
