#ifndef huffman_main_h
#define huffman_main_h

#include "min-heap.h"
#include "character-frequency.h"
#include "huf_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct huffman_config huffman_config;

int main(int argc, char *argv[]);
int huffmanMain(int argc, char *argv[]);
huffman_config parseArgs(int argc, char *argv[]);
char *convert(huffman_config configuration);
int save(char *output, char *outputPath);

#endif //huffman_main_h
