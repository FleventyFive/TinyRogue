CC=clang
CFLAGS=-g -c -Wall -Wextra -O0
NAME=rl
LDFLAGS=-lncurses
OBJ=obj
SRC=src
TARGET=target

all: $(NAME)

$(NAME): main.o
	mkdir -p $(TARGET)
	$(CC) $(OBJ)/*.o -o $(TARGET)/$(NAME) $(LDFLAGS)

%.o: $(SRC)/%.c
	mkdir -p $(OBJ)
	$(CC) $(CFLAGS) $< -o $(OBJ)/$@

run:
	./$(TARGET)/$(NAME)

clean:
	rm -Rf $(OBJ) $(TARGET)
