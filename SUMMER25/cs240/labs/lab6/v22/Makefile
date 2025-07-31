CC = gcc
CFLAGS = -Wall -g
OBJ = main11.o readinput.o printoutput.o
TARGET = main12.bin
LIB = libfileproc.a

all: $(TARGET)

$(TARGET): $(OBJ) $(LIB)
	$(CC) -o $@ $(OBJ)

$(LIB): readinput.o printoutput.o
	ar rcs $@ $^

%.o: %.c funcs11.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET) $(LIB)
