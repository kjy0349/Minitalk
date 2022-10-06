# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 15:47:18 by jeykim            #+#    #+#              #
#    Updated: 2022/10/06 18:39:04 by jeykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC		= ft_atoi.c ft_printf.c print_strnum.c print_uhex.c client.c client_bonus.c server.c server_bonus.c
NAME	= client
NAME1	= server

OBJECT_C	= ft_atoi.o ft_printf.o print_strnum.o print_uhex.o client.o
OBJECT_S	= ft_printf.o print_strnum.o print_uhex.o server.o
OBJECT_BONUS_C	= ft_atoi.o ft_printf.o print_strnum.o print_uhex.o client_bonus.o
OBJECT_BONUS_S	= ft_printf.o print_strnum.o print_uhex.o server_bonus.o

INCS	= .

ifdef EXIST_BONUS
	OBJC = ${OBJECT_BONUS_C}
	OBJS = ${OBJECT_BONUS_S}
else
	OBJC = ${OBJECT_C}
	OBJS = ${OBJECT_S}
endif

all : ${NAME} ${NAME1}

.c.o :
	${CC} ${CFLAGS} -c ${SRC} -I${INCS}

${NAME} : ${OBJC}
	${CC} ${CFLAGS} ${OBJC} -o ${NAME}

${NAME1} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME1}

clean :
	rm -f ${OBJECT_C} ${OBJECT_BONUS_C} ${OBJECT_S} ${OBJECT_BONUS_S}

fclean : clean
	rm -f ${NAME} ${NAME1}

re : fclean all

bonus : 
	make EXIST_BONUS=1 all

.PHONY : all clean fclean re .c.o bonus
