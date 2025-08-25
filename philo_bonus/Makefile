# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/18 11:33:26 by rfleritt          #+#    #+#              #
#    Updated: 2025/08/25 10:46:34 by rfleritt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

LDFLAGS = -lpthread
RM = rm -f

SRC = ./src/main.c ./src/parse.c ./src/init.c ./src/utils.c ./src/print.c \
	./src/philo_routine.c
OBJ = $(SRC:.c=.o)

all: ${NAME}

${NAME}: ${OBJ}
			${CC} ${SRC} ${CFLAGS} ${LDFLAGS} -o ${NAME}

clean: 
					${RM} ${OBJ}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re