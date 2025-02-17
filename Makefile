SRCS = pipex.c pipe_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g

NAME = pipex

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L libft -lft -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
