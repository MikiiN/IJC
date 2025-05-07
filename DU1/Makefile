# Makefile
# Řešení IJC-DU1, příklad a), 10.03.2022
# Autor: Michal Žatečka, FIT
# 

CC=gcc
CFLAGS= -g -std=c11 -pedantic -Wall -Wextra

all: primes primes-i steg-decode

run: primes primes-i
	./primes
	./primes-i

primes: primes.o eratosthenes.o error.o bitset.h
	$(CC) primes.o eratosthenes.o error.o -o primes

primes-i: primes-i.o eratosthenes-i.o error.o bitset-i.o
	$(CC) primes-i.o eratosthenes-i.o error.o bitset-i.o -o primes-i

primes.o: primes.c eratosthenes.o bitset.h error.h
	$(CC) $(CFLAGS) -c primes.c

primes-i.o: primes.c eratosthenes-i.o bitset.h error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c primes.c -o primes-i.o

eratosthenes.o: eratosthenes.c eratosthenes.h bitset.h error.h
	$(CC) $(CFLAGS) -c eratosthenes.c

eratosthenes-i.o: eratosthenes.c eratosthenes.h bitset.c bitset.h error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c eratosthenes.c -o eratosthenes-i.o

bitset-i.o: bitset.c bitset.h error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c bitset.c -o bitset-i.o

error.o: error.c error.h
	$(CC) $(CFLAGS) -c error.c


steg-decode: ppm.o steg-decode.o eratosthenes.o error.o
	$(CC) steg-decode.o ppm.o eratosthenes.o error.o -o steg-decode

steg-decode.o: steg-decode.c ppm.h ppm.c eratosthenes.h bitset.h error.h
	$(CC) $(CFLAGS) -c steg-decode.c

ppm.o: ppm.c ppm.h error.h
	$(CC) $(CFLAGS) -c ppm.c

clean:
	rm -f *.o && rm -f primes && rm -f primes-i && rm -f steg-decode