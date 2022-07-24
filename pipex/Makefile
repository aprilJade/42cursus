NAME	=	pipex
CFLAG	=	-Wall -Wextra -Werror
SRCS	= 	main.c
OBJS	=	$(SRCS:c=o)

ifdef DEBUG
	CFLAG += -g -fsanitize=address
endif

%.o:	%.c
	cc $(CFLAG) -c $< -o $@ 

$(NAME):$(OBJS)
	cc $(CFLAG) -o $(NAME) $(OBJS)

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
