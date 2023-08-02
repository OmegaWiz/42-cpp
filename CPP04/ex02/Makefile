# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 19:32:50 by kkaiyawo          #+#    #+#              #
#    Updated: 2023/08/02 08:00:37 by kkaiyawo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 ### EXECUTABLE ###
NAME			=	Animal02

### FILES ###
SRC_FILE		=	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp \
					Brain.cpp
HEADER_FILE		=	Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp\
					Brain.hpp

### PATH ###
SRC				=	${addprefix ${BUILD_DIR},${SRC_FILE}}

### OBJECTS ###
SRC_OBJ			=	${SRC:%.cpp=%.o}

### COMPILATION ###
CC				=	c++
CFLAG			=	-g -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98
RM				=	rm -f

all:			${NAME}

${NAME}:		${SRC_OBJ}
					${CC} ${CFLAG} ${SRC_OBJ} -o ${NAME}

%.o:			%.cpp ${HEADER_FILE}
					${CC} ${CFLAG} -c -o $@ $<

clean:
					${RM} ${SRC_OBJ}

fclean:			clean
					${RM} ${NAME}

re:				fclean all

test:			all
					./${NAME}

PHONY:			all library clean fclean re
