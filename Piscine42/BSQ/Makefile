NAME = bsq

SRC = srcs/*.c

INCLUDES = includes

all: $(NAME)

$(NAME):
		gcc -Wall -Werror -Wextra -O3 -o $(NAME) $(SRC)
clean:
		/bin/rm -f
fclean:
		/bin/rm -f $(NAME)
re: fclean all

