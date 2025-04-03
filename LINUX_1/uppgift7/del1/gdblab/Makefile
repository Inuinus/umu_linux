CC = gcc
CFLAGS = -g -Wall
LIBFLAG = -L. -lgdb -Wl,-rpath,.

all:	program

program:	main.c libgdb.so
		$(CC) $(CFLAGS)  -o program main.c $(LIBFLAG)

libgdb.so:	lib/gdblab.c lib/gdblab.h 
		$(CC) $(CFLAGS) -c -fPIC lib/gdblab.c
		$(CC) $(CFLAGS) -shared -fPIC -o libgdb.so gdblab.o
		
