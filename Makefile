# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=gcc
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-std=c99 -Wall -O3 -g

all: huffman-codec

test: main.c src/huffman.c test/test_main.c 
	$(CC) $(CFLAGS) main.c src/huffman.c test/test_main.c test/test_huffman.c -o bin/huffman-codec 

huffman-codec: src/main.c
	$(CC) $(CFLAGS) src/main.c src/huffman.c -o bin/huffman-codec

clean:
	rm -v bin/* && rm -v *o huffman-codec	