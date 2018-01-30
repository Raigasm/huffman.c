# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=gcc
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-std=c99 -Wall -O3 -g

all: clean huffman-codec

test: clean log.o main.c src/huffman.c test/test_main.c
	$(CC) $(CFLAGS) main.c src/huffman.c test/test_main.c test/test_huffman.c -o bin/huffman-codec

huffman-codec: log.o src/main.c src/huffman.c
	$(CC) $(CFLAGS) log.o src/main.c src/huffman.c -o bin/huffman-codec

log.o: src/log.c
	$(CC) $(CFLAGS) src/log.c -c -DLOG_USE_COLOR

clean:
	rm -rvf *o huffman-codec *out bin/*