CC = gcc
CFLAGS = -Wall -g

all: packbin2bit

packbin2bit: main.o packfile.o unpackfile.o
	$(CC) $(CFLAGS) -o packbin2bit main.o packfile.o unpackfile.o

main.o: main.c funcs15.h
	$(CC) $(CFLAGS) -c main.c

packfile.o: packfile.c funcs15.h
	$(CC) $(CFLAGS) -c packfile.c

unpackfile.o: unpackfile.c funcs15.h
	$(CC) $(CFLAGS) -c unpackfile.c

clean:
	rm -f *.o packbin2bit
