NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = pipex.c utils.c
LIBFT = libft/libft.a

$(NAME) :
	make all -C libft
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all