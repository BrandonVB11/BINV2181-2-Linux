CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

make: lireEtEcrire lireEntierV1 lireEntierV2 lire

lireEntierV1: lireEntierV1.o utils_v1.o
	gcc $(CFLAGS) -o lireEntierV1 lireEntierV1.o utils_v1.o

lireEntierV2: lireEntierV2.o utils_v1.o
	gcc $(CFLAGS) -o lireEntierV2 lireEntierV2.o utils_v1.o

lireEtEcrire: lireEtEcrire.o utils_v1.o
	gcc $(CFLAGS) -o lireEtEcrire lireEtEcrire.o utils_v1.o

lire: lire.o utils_v1.o
	gcc $(CFLAGS) -o lire lire.o utils_v1.o

lireEtEcrire.o: lireEtEcrire.c utils_v1.h
	gcc $(CFLAGS) -c lireEtEcrire.c

lire.o: lire.c utils_v1.h
	gcc $(CFLAGS) -c lire.c

lireEntierV1.o: lireEntierV1.c utils_v1.h
	gcc $(CFLAGS) -c lireEntierV1.c

lireEntierV2.o: lireEntierV2.c utils_v1.h
	gcc $(CFLAGS) -c lireEntierV2.c

utils_v1.o: utils_v1.c utils_v1.h
	gcc $(CFLAGS) -c utils_v1.c

clean:
	rm -f *.o
	rm -f maj min lireEtEcrire lireEntierV1 lireEntierV2