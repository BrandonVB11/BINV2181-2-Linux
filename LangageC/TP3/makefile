CFLAGS=-std=c11 -pedantic -Wvla -Wall -Werror -D_DEFAULT_SOURCE -g

testplaylist: testplaylist.o playlist.o track.o
	cc -o testplaylist testplaylist.o playlist.o track.o

track.o: track.c track.h
	cc -c track.c

playlist.o: playlist.c playlist.h track.h
	cc -c playlist.c

testplaylist.o: testplaylist.c playlist.h track.h
	cc -c testplaylist.c

clean:
	rm -f *.o
	rm -f testplaylist