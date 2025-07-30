CC = gcc
CFLAGS = -Wall -g

all: minsh

minsh: main.o
	$(CC) $(CFLAGS) -o minsh main.o

main.o: main.c funcs21.h
	$(CC) $(CFLAGS) -c main.c
clean:
	rm -f *.o minsh
