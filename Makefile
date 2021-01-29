#
# Noah Kuhn attempted to make a Makefile for the linked list demo. It's about as simple as it gets.
#

CC=gcc
CFLAGS=-I.
DEPS = list.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

linkedlistdemo: linkedlist.o
	$(CC) -o linkedlist linkedlist.o