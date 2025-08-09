# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/19 11:52:48 by rfleritt          #+#    #+#              #
#    Updated: 2025/07/21 17:41:33 by rfleritt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f

SRC = ./src/main.c ./src/utils.c ./src/parse.c ./src/init.c
OBJ = $(SRC:.c=.o)

all: ${NAME}

${NAME}: ${OBJ}
			${CC} ${SRC} ${CFLAGS} -o ${NAME}

clean: 
					${RM} ${OBJ}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re