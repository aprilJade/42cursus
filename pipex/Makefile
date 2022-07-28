# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 12:26:18 by seonggyk          #+#    #+#              #
#    Updated: 2022/07/28 17:57:45 by seonggyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
BONUS_NAME		=	pipex_bonus
CFLAG			=	-Wall -Wextra -Werror -g -fsanitize=address
INCLUDES		=	-I./includes/
BONUS_INCLUDES	=	-I./includes_bonus/
SRC				=	main.c \
					pipex_utils.c string_utils.c string_utils2.c 
BONUS_SRC		=	main_bonus.c \
					pipex_utils_bonus.c \
					string_utils_bonus.c string_utils2_bonus.c
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
	cc $(CFLAG) $(INCLUDES) -o $(NAME) $(OBJS)

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
	cc $(CFLAG) $(BONUS_INCLUDES) -o $(BONUS_NAME) $(BONUS_OBJS)

.PHONY: all clean fclean re debug bonus
