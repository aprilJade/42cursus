NAME	=	libft.a

LIB		=	ar -rcs

CC		=	gcc

FLAG	=	-Wall -Wextra -Werror

INCLUDE	=	-I includes/

OBJ_DIR	=	obj

SRCS	=	$(notdir $(wildcard *.c))

OBJS	=	$(SRCS:.c=.o)

OBJECTS	=	$(patsubst %.o, $(OBJ_DIR)/%.o, $(OBJS))

TARGET	=	$(NAME)

ifeq (, $(wildcard $(OBJ_DIR)))
$(shell mkdir $(OBJ_DIR))
endif

all		:	$(TARGET)

clean	:	
	rm -rf $(OBJECTS)

fclean	:	clean
	rm -rf $(TARGET)

re		:	fclean all

$(OBJ_DIR)/%.o	: %.c
	$(CC) $(FLAG) -c $< -o $@ $(INCLUDE)

$(NAME)	:	$(OBJECTS)
	$(LIB) $(NAME) $(OBJECTS)

.PHONY	:	all clean fclean re
