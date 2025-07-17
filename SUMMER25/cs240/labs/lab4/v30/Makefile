
CC = gcc
CFLAGS = -Wall -g

all: filescramble

filescramble: main.o inputproc.o fileproc.o
	$(CC) $(CFLAGS) -o filescramble main.o inputproc.o fileproc.o

main.o: main.c funcs30.h
	$(CC) $(CFLAGS) -c main.c

inputproc.o: inputproc.c funcs30.h
	$(CC) $(CFLAGS) -c inputproc.c

fileproc.o: fileproc.c funcs30.h
	$(CC) $(CFLAGS) -c fileproc.c

clean:
	rm -f *.o filescramble
