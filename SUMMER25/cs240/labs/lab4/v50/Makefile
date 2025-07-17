CC = gcc
CFLAGS = -Wall -g
OBJ = main.o findsize.o readvectors.o outprodcalc.o printres.o
TARGET = outerproduct

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

%.o: %.c funcs40.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
