CC =					g++

FLAGS =					-Wno-depecrated

RM =					rm -rf

DIR_SRC =				./src/

DIR_HEADERS =			./inc/

DIR_OBJ =				./

INC_DEPENDENCIES =		-Idependencies/include

LIB_DEPENDENCIES =		-Ldependencies/lib

GLAD = 					glad/glad.c

FRAME =					-lglfw -framework OpenGL -framework Cocoa -framework IOKit \
						-framework CoreVideo -framework CoreFoundation


SRC =		$(addprefix $(DIR_SRC), $(SRC))

COMPIL =	$(FLAGS) $(FRAME)

OBJ =		$(SRC:.c=.o)

