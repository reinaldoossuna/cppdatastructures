CC=g++
CFLAGS=-I.
DEPS = singly_ll.h
OBJ=main.o singly_ll.o
BIN=output

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

singly_ll: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

