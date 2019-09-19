SRCS		= src/main.c src/ft_str.c

OBJS		= ${SRCS:.c=.o}

INCLUDES	= include

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I${INCLUDES}

EXE			= ft_cat

all:		${EXE}

re:			fclean all

${EXE}:		${OBJS}
			${CC} ${CFLAGS} -o ${EXE} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${EXE}

.PHONY:		all clean fclean
