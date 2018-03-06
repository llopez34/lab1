all: llist


llist: llist.o
	cc -o llist llist.o

llist.o: llist.c llist.h
	cc -c llist.c

clean:
	rm llist llist.o
