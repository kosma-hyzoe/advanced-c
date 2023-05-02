CC = gcc
CFLAGS = -Wall -std=c89

SRC = mod.c main.c
OBJ = mod.o main.o

PROG = helloWorld

all: $(PROG)

$(PROG):$(OBJ) 
	$(CC) $(OBJ) -o $(PROG)

clean:
	rm -f $(OBJ) $(PROG)