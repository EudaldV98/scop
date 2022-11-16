# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:41:30 by jvaquer           #+#    #+#              #
#    Updated: 2022/11/16 16:57:02 by jvaquer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop

CXX =					clang++

FLAGS =					-Wno-deprecated

RM =					rm -rf

DIR_SRC =				./src/

DIR_GLAD =				./glad/

DIR_HEADERS =			./inc/

DIR_OBJ =				./

INC_DEPENDENCIES =		dependencies/include

GLAD_DEPENDENCIES =		dependencies/include/glad

LIB_DEPENDENCIES =		dependencies/lib

GLAD = 					glad.c

FRAME =					-lglfw -framework OpenGL -framework Cocoa -framework IOKit \
						-framework CoreVideo -framework CoreFoundation

SRC =					main.cpp


CXX_SRCS =		$(addprefix $(DIR_SRC), $(SRC))

C_SRCS =		$(addprefix $(DIR_GLAD), $(GLAD))

COMPIL =	$(FLAGS) $(FRAME)

OBJ =		$(CXX_SRCS:.cpp=.o)

OBJ_GLAD =	$(C_SRCS:.c=.o)


all:	$(NAME)

$(NAME):	$(OBJ) $(OBJ_GLAD)

			$(CXX) $(FRAME) $(OBJ) $(OBJ_GLAD) -o $(NAME)
			$(MAKE) -C ./ clean

%.o: %.c
			$(CXX) -c $^ -I$(INC_DEPENDENCIES) $(FLAGS) -o $@

%.o: %.cpp
			$(CXX) -c $^ -I$(INC_DEPENDENCIES) -L$(LIB_DEPENDENCIES) $(FLAGS) -o $@

clean:
			$(RM) $(OBJ) $(OBJ_GLAD)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all, clean, fclean, re
