CC=gcc
CFLAGS=-std=c99 -Wall -O3 -g

all: clean huffman-codec

test: clean log.o src/huffman.c test/test_main.c test/test_huffman.c
	$(CC) $(CFLAGS)	log.o src/huffman.c test/test_huffman.c test/test_main.c -o bin/huffman-codec

huffman-codec: log.o src/main.c src/huffman.c
	$(CC) $(CFLAGS) log.o src/main.c src/huffman.c -o bin/huffman-codec

log.o: src/log.c
	$(CC) $(CFLAGS) src/log.c -c -DLOG_USE_COLOR

clean:
	rm -rvf *o huffman-codec *out bin/*