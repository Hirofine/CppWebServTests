CC=g++
CFLAGS=-W -Wall -ansi -pedantic -I
LDFLAGS=
EXEC=hangman
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

hangman: $(OBJ)
    $(CC) -o $@ $^ $(LDFLAGS)

main.o: Hangman.cpp

%.o: %.c
    $(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
    rm -rf *.o

mrproper: clean
    rm -rf $(EXEC)