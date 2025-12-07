NAME        = push_swap
INCLUDE     = include
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRC         = $(wildcard src/*.c utilities/*.c operations/*.c)
OBJ         = $(SRC:.c=.o)

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I $(INCLUDE)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re