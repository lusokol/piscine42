SRCS		= src/main.c src/ft_hexdump.c src/ft_str.c

OBJS		= ${SRCS:.c=.o}

INCLUDES	= include

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I${INCLUDES}

EXE			= ft_hexdump

all:		${EXE}

re:			fclean all

${EXE}:		${OBJS}
			gcc ${CFLAGS} -o ${EXE} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${EXE}

.PHONY:		all clean fclean
