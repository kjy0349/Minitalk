CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC		= ft_atoi.c ft_printf.c print_strnum.c print_uhex.c
CL		= client.c
SR		= server.c

OBJECT_C= ${SRC:.c=.o} client.o
OBJECT_S= ${SRC:.c=.o} server.o
INCS	= .

all : ${OBJECT_C} server.o
	${CC} ${CFLAGS} -I${INCS} ${SRC} ${CL} -o client
	${CC} ${CFLAGS} -I${INCS} ${SRC} ${SR} -o server

clean :
	rm -f ${OBJECT_C} ${OBJECT_S}

fclean : clean
	rm -f client
	rm -f server

re : clean all

.PHONY : all clean re
