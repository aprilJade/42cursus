NAME	=	libft.a
CC		=	gcc
LIB		=	ar
LIB_FLAG=	rcs
FLAG	=	-Wall -Wextra -Werror
INCLUDE	=	-Iincludes/
SRC_DIR	=	./srcs
SRCS	=	srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS	=	srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
TARGET	=	$(NAME)
all		:	$(TARGET)
clean	:	
	rm -rf $(OBJS)
fclean	:	clean
	rm -rf $(TARGET)
re		:	fclean all
$(SRC_DIR)/%.o	: $(SRCS)
	$(CC) $(FLAG) -c $< -o $@
$(NAME)	:	$(OBJS)
	$(LIB) $(LIB_FLAG) $(NAME) $(OBJS)
.PHONY	:	all clean fclean re
