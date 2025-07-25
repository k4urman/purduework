CC = gcc
CFLAGS = -Wall -g
TARGET = linesmod

all: $(TARGET)

$(TARGET): main.o linesinfo.o buildstruct.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o linesinfo.o buildstruct.o

main.o: main.c funcs16.h
	$(CC) $(CFLAGS) -c main.c

linesinfo.o: linesinfo.c funcs16.h
	$(CC) $(CFLAGS) -c linesinfo.c

buildstruct.o: buildstruct.c funcs16.h
	$(CC) $(CFLAGS) -c buildstruct.c

clean:
	rm -f $(TARGET) *.o
