# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/30 14:08:18 by ysumeral          #+#    #+#              #
#    Updated: 2026/01/31 22:29:49 by ysumeral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX 		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC			=	src/main.cpp \
				src/ScalarConverter.cpp
OBJ			=	$(SRC:.cpp=.o)
NAME		=	converter

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re