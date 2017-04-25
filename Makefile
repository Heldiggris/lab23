CC = gcc
CFLAGS = -g -std=c99 -w -pipe -O3

all: lab23

tree:    tree.o
	$(CC) $^ -o $@

lab23:  tree.o lab23.o
	$(CC) $^ -o $@

clean:
	rm -f *.o

cleanall:
	rm -f lab23 *.o

