SRCS		= main.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

EXE			= ft_display_file

all:		${EXE}

${EXE}:		${OBJS}
			gcc ${CFLAGS} -o ${EXE} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${EXE}

.PHONY:		all clean fclean
