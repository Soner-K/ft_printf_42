SRC		=	ft_printf.c convert.c

HEADER		=	ft_printf.h

OBJ		=	$(SRC:.c=.o)

OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

NAME		=	libftprintf.a

CC		=	cc

CFLAGS		=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			make -C libft
			cp libft/libft.a $(NAME)
			ar -q $(NAME) $(OBJ)

bonus		:	$(NAME) $(OBJ_BONUS)
			ar -rc $(NAME) $(OBJ_BONUS)
			
%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean		:	
			rm -f $(OBJ) $(OBJ_BONUS)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re bonus
