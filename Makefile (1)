CC=gcc
CFLAGS=-std=c99 -Wall -O3 -g

all: clean huffman-codec

huffman.o: log.o huff_file.o min-heap.o character_frequency.o src/huffman.c
	$(CC) $(CFLAGS)	log.o  min-heap.o character_frequency.o huff_file.o src/huffman.c -c

test: log.o huffman.o src/tests.c
	$(CC) $(CFLAGS)	log.o huffman.o lib/parson/parson.c src/huff_file.c src/character_frequency.c  src/tests.c -o bin/huffman-codec

huffman-codec: log.o huffman.o src/main.c
	$(CC) $(CFLAGS) log.o huffman.o src/main.c -o bin/huffman-codec

min-heap.o: src/min-heap.c
	$(CC) $(CFLAGS) src/min-heap.c -c

huff_file.o: src/huff_file.c lib/parson/parson.c
	$(CC) $(CFLAGS) lib/parson/parson.c src/huff_file.c -c

character_frequency.o: src/character_frequency.c
	$(CC) $(CFLAGS) src/character_frequency.c -c

log.o: src/log.c
	$(CC) $(CFLAGS) src/log.c -c -DLOG_USE_COLOR

clean:
	rm -rvf *o huffman-codec *out bin/*