# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 15:49:02 by janhan            #+#    #+#              #
#    Updated: 2024/04/24 16:01:16 by janhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRCS = megaphone.cpp
OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAG} ${OBJS} -o ${NAME}

%.o : %.cpp
	${CC} ${CFLAG} -c $< -o $@

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re :
	fclean
	all

.PHONY = all clean fclean re
