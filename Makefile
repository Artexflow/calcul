NAME = calc
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = compute_machine.c engine.c list_utils.c main.c utils.c
OBJ = $(subst .c,.o,$(SRC))

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
