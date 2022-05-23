CC=g++
CFLAGS=-I.
DEPS = functions.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: factorial.o main.o hello.o 
	$(CC) -o main factorial.o main.o hello.o