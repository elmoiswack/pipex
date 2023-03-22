NAME	:=	libft.a

HEADER	:=	libft.h

SRC	:=	ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_split.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_printf.c \
		ft_printf_pointer.c \
		ft_printf_char.c \
		ft_printf_int.c \
		ft_printf_string.c \
		ft_printf_unsigndec.c \
		ft_printf_hexalower.c \
		ft_printf_hexaupper.c \
		ft_intcheck.c \
		ft_mallocaaa.c \
		

OBJ := $(SRC:.c=.o)

CC	:=	gcc

CFLAGS	:=	-Wall -Werror -Wextra

$(NAME): $(OBJ)
	ar -cr $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

all: $(NAME) 

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re