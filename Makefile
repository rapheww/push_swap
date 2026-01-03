SRC = algo.c \
	change_stack.c \
	check_limits.c \
	count_operations.c \
	find_index.c \
	get_value.c \
	lil_algo.c \
	operations.c \
	operations2.c \
	operations3.c \
	pushswap.c \
	free.c \

LIB = libft/libft.a \
	ft_printf/libftprintf.a \

OBJ = $(SRC:.c=.o)

CC = cc -Wall -Werror -Wextra
NAME = push_swap

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${SRC} ${LIB} -o ${NAME} -g3

clean:
		rm -f ${OBJ}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean re fclean