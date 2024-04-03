CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

PROGS =  distributeur ecran

all: $(PROGS)

distributeur: distributeur.o utils_v2.o
	gcc $(CFLAGS) -o distributeur distributeur.o utils_v2.o

ecran: ecran.o utils_v2.o
	gcc $(CFLAGS) -o ecran ecran.o utils_v2.o

utils_v2.o: utils_v2.c utils_v2.h
	gcc $(CFLAGS) -c utils_v2.c

distributeur.o: distributeur.c utils_v2.h
	gcc $(CFLAGS) -c distributeur.c

ecran.o: ecran.c utils_v2.h
	gcc $(CFLAGS) -c ecran.c

clean:
	rm -f *.o
	rm -f $(PROGS)