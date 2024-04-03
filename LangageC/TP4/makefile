CFLAGS=-std=c11 -pedantic -Wvla -Wall -Werror -D_DEFAULT_SOURCE -g

biblio: biblio.o utils_v1.o
	cc -o biblio biblio.o utils_v1.o

biblio.o: biblio.c biblio.h
	cc -c biblio.c

utils_v1.o: utils_v1.c utils_v1.h
	cc -c utils_v1.c