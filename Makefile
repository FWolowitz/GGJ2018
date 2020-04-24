##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for bacterium
##

SRC		=	src/main.cpp			\
			src/Game.cpp			\
			src/TextureManager.cpp 	\
			src/GameObject.cpp		\
			src/MapObject.cpp 		\
			src/Map.cpp				\
			src/Eagle.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME		=	bacterium

CPPFLAGS	+=	-Wall -Werror -Wextra -std=gnu++14 -lSDL2 -lSDL2_image -lSDL2_mixer -g3

all: $(NAME)

$(NAME):	$(OBJ)
	-g++ $(OBJ) -o $(NAME) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
