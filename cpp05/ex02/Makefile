# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 19:32:50 by kkaiyawo          #+#    #+#              #
#    Updated: 2023/09/03 13:33:20 by kkaiyawo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 ### EXECUTABLE ###
NAME			=	Bureaucrat02

### FILES ###
SRC_FILE		=	main.cpp AException.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
HEADER_FILE		=	AException.hpp Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

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

ffclean:		fclean
					${RM} *_shrubbery

re:				fclean all

test:			all
					./${NAME}

ctest:			ffclean test

leaks:			all
					leaks -atExit -- ./$(NAME)

PHONY:			all clean fclean re
