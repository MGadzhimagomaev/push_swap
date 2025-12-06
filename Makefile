NAME		=	push_swap.a
INCLUDE		=	include
LIBFT		=	libft
SRC_DIR		=	$(wildcard src/*.c utilities/*.c operations/*.c)

SRC_FILES	=	main instructions

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			ar rcs $(NAME) $(OBJ)

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $@

all:		$(NAME)

clean:
	rm -rf	$(OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	rm -rf	$(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re