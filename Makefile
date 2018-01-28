# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=gcc
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-std=c99 -Wall -O3 -g

all: huffman-codec

test: main.o huffman-codec.o min-heap.o character_frequency.o huf_file.o test/test_main.c 
		$(CC) test/test_main.c main.o huffman-codec.o min-heap.o character_frequency.o huf_file.o -o bin/huffman-codec

huffman-codec: main.o huffman-codec.o min-heap.o character_frequency.o huf_file.o 
    $(CC) main.o huffman-codec.o min-heap.o character_frequency.o huf_file.o -o bin/huffman-codec

main.o: src/main.c
    $(CC) $(CFLAGS) src/main.c

huf_file.o: src/huf_file.c
    $(CC) $(CFLAGS) src/huf_file.c

character_frequency.o: src/character_frequency.c
	$(CC) $(CFLAGS) src/character_frequency.c

min-heap.o: src/min-heap.c
	$(CC) $(CFLAGS) src/min-heap.c 

huffman-codec.o: huffman-codec.c
	$(CC) $(CFLAGS) huffman-codec.c

clean:
    rm -v *o huffman-codec && rm -v bin/*