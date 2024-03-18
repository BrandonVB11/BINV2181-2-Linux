CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

PROGS = exo.2.A.1 exo.2.A.2 exo.2.B exo.2.C

all: $(PROGS)

exo.2.A.1: exo.2.A.1.o utils_v1.o
	gcc $(CFLAGS) -o exo.2.A.1 exo.2.A.1.o utils_v1.o

exo.2.A.2: exo.2.A.2.o utils_v1.o
	gcc $(CFLAGS) -o exo.2.A.2 exo.2.A.2.o utils_v1.o

exo.2.B: exo.2.B.o utils_v1.o
	gcc $(CFLAGS) -o exo.2.B exo.2.B.o utils_v1.o

exo.2.C: exo.2.C.o utils_v1.o
	gcc $(CFLAGS) -o exo.2.C exo.2.C.o utils_v1.o

exo.2.C.o: exo.2.C.c
	gcc $(CFLAGS) -c exo.2.C.c

exo.2.B.o: exo.2.B.c
	gcc $(CFLAGS) -c exo.2.B.c

exo.2.A.2.o: exo.2.A.2.c
	gcc $(CFLAGS) -c exo.2.A.2.c

exo.2.A.1.o: exo.2.A.1.c
	gcc $(CFLAGS) -c exo.2.A.1.c	

utils_v1.o: utils_v1.c utils_v1.h
	gcc $(CFLAGS) -c utils_v1.c


clean:
	rm -f *.o
	rm -f $(PROGS)