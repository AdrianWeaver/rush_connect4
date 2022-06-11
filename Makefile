NAME = connect4

CC	=	cc
CFLAGS	= -Wall -Wextra -Werror

LIB_FLAGS		= -L./libft

RM	=	rm -rf

HEADER			=	-Iincludes/ -Ilibft/includes/ -Ilibft/libft/
INCLUDE_LIB		= ./libft/libftprintf.a
VALGRIND 		= -O0 -g

SRCS = srcs/connect4.c srcs/grid.c srcs/utils.c srcs/ia.c

OBJ = $(SRCS:.c=.o)

%.o: %.c
		${CC} $(HEADER) ${CFLAGS} -c $< -o $@ $(VALGRIND)

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(HEADER) -o $(NAME) $(OBJ) $(INCLUDE_LIB) $(VALGRIND)
	echo "The $(NAME) has been build !"

clean :
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)

fclean : clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	echo "The $(NAME) has been deleted !"

re : fclean all

.PHONY: all clean fclean re