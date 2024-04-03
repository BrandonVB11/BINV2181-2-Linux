CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

PROGS = exo.4.1

all: $(PROGS)

exo.4.1: utils_v1.o exo.4.1.o
	gcc $(CFLAGS) -o exo.4.1 utils_v1.o exo.4.1.o

utils.o: utils_v1.c utils_v1.h
	gcc $(CFLAGS) -c utils_v1.c

exo.4.1.o: exo.4.1.c utils_v1.h
	gcc $(CFLAGS) -c exo.4.1.c

clean:
	rm -f *.o
	rm -f $(PROGS)