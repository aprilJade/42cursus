NAME	=	libft.a

LIB		=	ar -rcs

CC		=	gcc

FLAG	=	-Wall -Wextra -Werror

INCLUDE	=	-Ilibft.h

SRCS	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
			ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
			ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_isalpha.c
SRCS_BN	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
			ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstnew.c ft_lstsize.c

OBJS	=	$(SRCS:.c=.o)

OBJS_BN	=	$(SRCS_BN:.c=.o)

ifdef BONUS
	OBJECTS	= $(OBJS) $(OBJS_BN)
else
	OBJECTS = $(OBJS)
endif

TARGET	=	$(NAME)

all		:	$(TARGET)

bonus	:
	make BONUS=1 all
clean	:	
	rm -rf $(OBJECTS)

fclean	:	clean
	rm -rf $(TARGET)

re		:	fclean all

%.o	: %.c
	$(CC) $(FLAG) -c $< -o $@ $(INCLUDE)

$(NAME)	:	$(OBJECTS)
	$(LIB) $(NAME) $(OBJECTS)

.PHONY	:	all clean fclean re
