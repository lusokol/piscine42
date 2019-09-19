SRCS		= src/main.c src/ft_util.c src/ft_error.c

OBJS		= ${SRCS:.c=.o}

INCLUDES	= include

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I${INCLUDES}

EXE			= ft_tail

all:		${EXE}

re:			fclean all

${EXE}:		${OBJS}
			gcc ${CFLAGS} -o ${EXE} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${EXE}

.PHONY:		all clean fclean
