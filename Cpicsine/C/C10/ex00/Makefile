NAME	=	ft_display_file
CC		=	gcc
FLAG	=	-Wall -Wextra -Werror
SRCS	=	main.c
OBJS	=	$(SRCS:.c=.o)
TARGET	=	$(NAME)
all		:	$(TARGET)
clean	:	
	rm -rf $(OBJS)
fclean	:	clean
	rm -rf $(TARGET)
re		:	fclean all
$(NAME) :	$(OBJS)
	$(CC) $(SRCS) $(FLAG) -o $(NAME)
.PHONY	:	all clean fclean re
