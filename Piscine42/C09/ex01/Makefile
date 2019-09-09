# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusokol <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 15:34:36 by lusokol           #+#    #+#              #
#    Updated: 2019/09/09 15:44:13 by lusokol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =    libft.a

SRCS        =    ft_putchar.c        \
				 ft_putstr.c        \
				 ft_strlen.c        \
				 ft_strcmp.c        \
				 ft_swap.c            \

OBJS        =    $(SRCS:.c=.o)

INCLUDES    =    -I./includes/

CC        =    gcc

CFLAGS        = -Wall -Wextra -Werror

all:    $(NAME)

$(NAME):$(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean:    clean
	rm -f $(NAME)

re:    fclean all

.PHONY:    all clean fclean re
