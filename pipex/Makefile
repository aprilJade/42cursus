# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonggyk <seonggyk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 12:26:18 by seonggyk          #+#    #+#              #
#    Updated: 2022/07/27 12:39:07 by seonggyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
CFLAG			=	-Wall -Wextra -Werror
SRC				=	main.c pipex_utils.c memory_utils.c \
					string_utils.c string_utils2.c string_utils3.c \
					cmd_parser.c errors.c
OBJS			=	$(SRC:.c=.o)

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

.PHONY: all clean fclean re debug bonus
