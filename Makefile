##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## The makefile of arcade
##

CC	=	g++

CFLAGS	+=	-Wpedantic -pedantic-errors -w  -Wextra  -Wall -g3

NAME	=	plazza

THREADS	=	-pthread -lrt

SRC	=	$(shell find ./ -name '*.cpp')

OBJ	=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):
	@$(CC) $(SRC) $(CFLAGS) $(THREADS) -o $(NAME)
	@echo "The binairie $(NAME) build with no errors"

%.o:	%.cpp
	gcc -o $@ -c $< -g3

clean:
	@rm -f $(shell find . -name '*~')
	@rm -f $(OBJ)
	@echo "Every *~ and obj files has been cleaned"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(shell find . -name a.out)
	@echo "Every a.out and $(NAME) binaries has been cleaned"

re:	fclean all

.PHONY:	fclean	clean	re
