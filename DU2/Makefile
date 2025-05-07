# Makefile
# Řešení IJC-DU2, 14.04.2022
# Autor: Michal Žatečka, FIT

CPP=g++
CPPFLAGS=-std=c++17 -pedantic -Wall
CC=gcc
CFLAGS=-std=c11 -pedantic -Wall -Wextra
CLIBFLAGS=-c
STATICMODULES=htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o htab_free.o htab_hash_function.o htab_init.o htab_lookup_add.o htab_resize.o htab_size.o
DYNMODULES=htab_bucket_count-dynam.o htab_clear-dynam.o htab_erase-dynam.o htab_find-dynam.o htab_for_each-dynam.o htab_free-dynam.o htab_hash_function-dynam.o htab_init-dynam.o htab_lookup_add-dynam.o htab_resize-dynam.o htab_size-dynam.o
CDYNFLAGS=-fPIC -c 

all: tail wordcount wordcount-dynamic libhtab.a libhtab.so

test: wordcount.o $(MODULES)
	$(CC) $(STATICMODULES) wordcount.o -o test

tail: tail.c
	$(CC) $(CFLAGS) tail.c -o tail

wordcount: wordcount.c libhtab.a io.o
	$(CC) -static $(CFLAGS) wordcount.c io.o -L. -lhtab -o wordcount

wordcount-dynamic: wordcount.c libhtab.so io.o
	$(CC) $(CFLAGS) -Wl,-R -Wl,. wordcount.c io.o -L. -lhtab -o wordcount-dynamic

wordcount.o: wordcount.c htab.h io.o
	$(CC) $(CFLAGS) -c wordcount.c io.o -o wordcount.o

io.o: io.c io.h
	$(CC) $(CFLAGS) -c io.c -o io.o

libhtab.so: $(DYNMODULES)
	cc -shared -fPIC $(DYNMODULES) -o libhtab.so

libhtab.a: $(STATICMODULES)
	ar -rc libhtab.a $(STATICMODULES)

wordcount_cpp: wordcount-.cc
	$(CPP) $(CPPFLAGS) wordcount-.cc -o wordcount_cpp

# moduly pro statickou knihovnu
htab_bucket_count.o: htab_bucket_count.c htab.h htab_private.h
	$(CC) $(CLIBFLAGS) htab_bucket_count.c -o htab_bucket_count.o

htab_erase.o: htab_erase.c htab_hash_function.o htab_resize.o htab.h htab_private.h
	$(CC) $(CLIBFLAGS) htab_erase.c -o htab_erase.o

htab_for_each.o: htab_for_each.c htab.h htab_private.h
	$(CC) $(CLIBFLAGS) htab_for_each.c -o htab_for_each.o

htab_hash_function.o: htab_hash_function.c htab.h htab_private.h
	$(CC) $(CLIBFLAGS) htab_hash_function.c -o htab_hash_function.o

htab_lookup_add.o: htab_lookup_add.c htab_hash_function.o htab_find.o htab.h htab_private.h
	$(CC) $(CLIBFLAGS) htab_lookup_add.c -o htab_lookup_add.o

htab_size.o: htab_size.c htab.h htab_private.h
	$(CC) $(CLIBFLAGS) htab_size.c -o htab_size.o

htab_clear.o: htab_clear.c htab.h htab_private.h
	$(CC) $(CLIBFLAGS) htab_clear.c -o htab_clear.o

htab_find.o: htab_find.c htab_hash_function.o htab.h htab_private.h
	$(CC) $(CLIBFLAGS) htab_find.c -o htab_find.o

htab_free.o: htab_free.c htab_clear.o htab.h htab_private.h
	$(CC) $(CLIBFLAGS) htab_free.c -o htab_free.o

htab_init.o: htab_init.c htab.h htab_private.h
	$(CC) $(CLIBFLAGS) htab_init.c -o htab_init.o

htab_resize.o: htab_resize.c htab_hash_function.o htab_init.o htab.h htab_private.h
	$(CC) $(CLIBFLAGS) htab_resize.c -o htab_resize.o

# moduly pro dynamickou knihovnu
htab_bucket_count-dynam.o: htab_bucket_count.c htab.h htab_private.h
	$(CC) $(CDYNFLAGS) htab_bucket_count.c -o htab_bucket_count-dynam.o

htab_erase-dynam.o: htab_erase.c htab_hash_function-dynam.o htab_resize-dynam.o htab.h htab_private.h
	$(CC) $(CDYNFLAGS) htab_erase.c -o htab_erase-dynam.o

htab_for_each-dynam.o: htab_for_each.c htab.h htab_private.h
	$(CC) $(CDYNFLAGS) htab_for_each.c -o htab_for_each-dynam.o

htab_hash_function-dynam.o: htab_hash_function.c htab.h htab_private.h
	$(CC) $(CDYNFLAGS) htab_hash_function.c -o htab_hash_function-dynam.o

htab_lookup_add-dynam.o: htab_lookup_add.c htab_hash_function-dynam.o htab_find-dynam.o htab.h htab_private.h
	$(CC) $(CDYNFLAGS) htab_lookup_add.c -o htab_lookup_add-dynam.o

htab_size-dynam.o: htab_size.c htab.h htab_private.h
	$(CC) $(CDYNFLAGS) htab_size.c -o htab_size-dynam.o

htab_clear-dynam.o: htab_clear.c htab.h htab_private.h
	$(CC) $(CDYNFLAGS) htab_clear.c -o htab_clear-dynam.o

htab_find-dynam.o: htab_find.c htab_hash_function-dynam.o htab.h htab_private.h
	$(CC) $(CDYNFLAGS) htab_find.c -o htab_find-dynam.o

htab_free-dynam.o: htab_free.c htab_clear-dynam.o htab.h htab_private.h
	$(CC) $(CDYNFLAGS) htab_free.c -o htab_free-dynam.o

htab_init-dynam.o: htab_init.c htab.h htab_private.h
	$(CC) $(CDYNFLAGS) htab_init.c -o htab_init-dynam.o

htab_resize-dynam.o: htab_resize.c htab_hash_function-dynam.o htab_init-dynam.o htab.h htab_private.h
	$(CC) $(CDYNFLAGS) htab_resize.c -o htab_resize-dynam.o

clean:
	rm -f *.o *.a *.so tail wordcount test wordcount_cpp wordcount-dynamic