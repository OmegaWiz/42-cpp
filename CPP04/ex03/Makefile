# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 19:32:50 by kkaiyawo          #+#    #+#              #
#    Updated: 2023/08/02 09:09:40 by kkaiyawo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 ### EXECUTABLE ###
NAME			=	Animal03

### FILES ###
SRC_FILE		=	main.cpp AMateria.cpp Cure.cpp Ice.cpp Character.cpp \
					MateriaSource.cpp
HEADER_FILE		=	ICharacter.hpp AMateria.hpp Cure.hpp Character.hpp\
					IMateriaSource.hpp Ice.hpp MateriaSource.hpp

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

leaks:			all
					leaks -atExit -- ./$(NAME)

val:			all
					valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

PHONY:			all library clean fclean re
