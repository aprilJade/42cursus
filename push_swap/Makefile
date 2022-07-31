# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonggyk <seonggyk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 12:26:18 by seonggyk          #+#    #+#              #
#    Updated: 2022/07/31 16:40:43 by seonggyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
CFLAG			=	-Wall -Wextra -Werror
INCLUDES		=	-I./includes/
SRC				=	main.c ft_atoi.c ft_split.c props.c stack.c \
					commands_r.c commands_rr.c commands_s.c \
					commands_p.c input_parser.c err.c solver.c
SRCS			=	$(addprefix ./srcs/, $(SRC))
OBJS			=	$(SRCS:.c=.o)

ifdef DEBUG
	CFLAG += -g -fsanitize=address
endif

%.o: %.c
	cc $(CFLAG) $(INCLUDES) -c $< -o $@ 

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

d:
	make fclean
	make DEBUG=1 all

.PHONY: all clean fclean re debug bonus
