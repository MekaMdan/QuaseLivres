CC=gcc
CFLAGS=-I.
DEPS = graph.h read.h
OBJ = main.o graph.o read.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
