CC=clang
CFLAGS=-g -c -Wall -Wextra -O0
NAME=roguelike
LDFLAGS=-lstdc++ -lncurses
OBJ=obj
SRC=src
TARGET=target

all: $(NAME)

$(NAME): main.o
	$(CC) $(OBJ)/*.o -o $(TARGET)/$(NAME) $(LDFLAGS)

%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $< -o $(OBJ)/$@

run:
	./$(TARGET)/$(NAME)
