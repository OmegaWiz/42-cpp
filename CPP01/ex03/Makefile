# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 19:32:50 by kkaiyawo          #+#    #+#              #
#    Updated: 2023/06/27 12:30:14 by kkaiyawo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 ### EXECUTABLE ###
NAME			=	human

### FILES ###
SRC_FILE		=	main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

### PATH ###
SRC				=	${addprefix ${BUILD_DIR},${SRC_FILE}}

### OBJECTS ###
SRC_OBJ			=	${SRC:%.cpp=%.o}

### COMPILATION ###
CC				=	c++
CFLAG			=	-g -Wall -Wextra -Werror -std=c++98
RM				=	rm -f

all:			${NAME}

${NAME}:		${SRC_OBJ}
					${CC} ${CFLAG} ${SRC_OBJ} -o ${NAME}

%.o:			%.cpp
					${CC} ${CFLAG} -c -o $@ $^

clean:
					${RM} ${SRC_OBJ}

fclean:			clean
					${RM} ${NAME}

re:				fclean all

.PHONY:			all library clean fclean re
