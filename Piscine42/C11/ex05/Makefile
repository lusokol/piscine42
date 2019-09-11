# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusokol <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 15:34:36 by lusokol           #+#    #+#              #
#    Updated: 2019/09/10 18:59:18 by lusokol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	doop.c			\
			ft_putnbr.c		\
			operateurs.c

SRCS_PATH	=	./srcs/
OBJS		=	$(addprefix $(SRCS_PATH), $(SRCS:.c=.o))
	INCLUDES	=	-I./includes/
	NAME		=	do-op
	CC			=	gcc
	CFLAGS		+=	-Wall -Wextra -Werror
	RM			=	rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)

fclean:			clean
	$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
