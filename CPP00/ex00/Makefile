# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 15:49:02 by janhan            #+#    #+#              #
#    Updated: 2024/04/24 20:55:44 by janhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		megaphone

CC				=		c++
CFLAGS			=		-Wall -Wextra -Werror -std=c++98

SRCS		=	megaphone.cpp
OBJS		=	$(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@echo $(CURSIVE)$(YELLOW) "      - Making $(NAME) -" $(NONE)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo $(CURSIVE)$(YELLOW) "        - Compiling $(NAME) -" $(NONE)

%.o : %.cpp
	@echo $(CURSIVE)$(YELLOW) "      - Making object files -" $(NONE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -fr $(OBJS)
	@echo $(CURSIVE)$(BLUE) "     - clean OBJ files -" $(NONE)

fclean : clean
	@rm -fr $(NAME)
	@echo $(CURSIVE)$(PURPLE)"      - clean $(NAME) file -"$(NONE)

re	:
	@make fclean
	@make all

.PHONY: all make clean fclean bonus re

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
PURPLE='\033[35m'
BLUE='\033[34m'
DELETELINE='\033[K;
