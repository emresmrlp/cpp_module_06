# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysumeral <ysumeral@student.42istanbul.com. +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/03 12:29:40 by ysumeral          #+#    #+#              #
#    Updated: 2026/02/03 13:05:49 by ysumeral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX 		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC			=	src/main.cpp \
				src/Serializer.cpp
OBJ			=	$(SRC:.cpp=.o)
NAME		=	serializer

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re