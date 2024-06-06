CC=gcc
CFLAGS=-Wall -Wextra -std=c99

corrector: corrector.o diccionario.o
	$(CC) $(CFLAGS) -o corrector corrector.o diccionario.o

corrector.o: corrector.c diccionario.h
	$(CC) $(CFLAGS) -c corrector.c

diccionario.o: diccionario.c diccionario.h
	$(CC) $(CFLAGS) -c diccionario.c

clean:
	rm -f corrector *.o