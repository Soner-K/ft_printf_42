SRC		=	ft_printf.c convert.c

HEADER		=	ft_printf.h

OBJ		=	$(SRC:.c=.o)

NAME		=	libftprintf.a

CC		=	cc

CFLAGS		=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			make -C libft
			cp libft/libft.a $(NAME)
			ar -q $(NAME) $(OBJ)
			
%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean			:	
			rm -f $(OBJ) libft/*.o libft/*.gch

fclean		:	clean
			rm -f $(NAME) libft/libft.a

re		:	fclean all

.PHONY		:	all clean fclean re
