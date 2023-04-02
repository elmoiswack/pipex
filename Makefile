NAME	:=	pipex

HEADER 	:= pipex.h

LIBFT 		:= ./libft

LIBFTLIB	:= $(LIBFT)/libft.a

HEADERS	:=	-I $(LIBFT)

SRC	:=	./srcs/main.c \
		./srcs/free_error.c \
		./srcs/arguments.c \
		./srcs/paths_creation.c \

OBJ := $(SRC:.c=.o)

CC	:=	gcc

CFLAGS	:=	-Wall -Wextra -Werror

all: libs $(NAME)

libs:
	$(MAKE) -C libft

$(NAME): $(OBJ)
	$(CC) $^ $(LIBFTLIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean:
	rm -f $(NAME) $(OBJ)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re