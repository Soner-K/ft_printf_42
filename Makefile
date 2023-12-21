SRC			=	src/ft_printf.c src/convert.c

SRC_LIBFT	=	libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_strlen.c

HEADER		=	includes/ft_printf.h

OBJ			=	$(SRC:.c=.o)

NAME		=	libftprintf.a

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

EXEC	=	exec

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			make -C ../libft
			cp ../libft/libft.a $(NAME)
			ar -q $(NAME) $(OBJ)
			
%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean			:	
			rm -f $(OBJ) ../src/*.o ../src/*.gch $(EXEC)

fclean		:	clean
			rm -f $(NAME) ../libft.a

re		:	fclean all

$(EXEC)		:	$(SRC) $(SRC_LIBFT)
				@$(CC) $(CFLAGS) $^ -o $@

run			:	$(EXEC)
				@./$(EXEC)

.PHONY		:	all clean fclean re run exec
