#ifndef huffman_h
#define huffman_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct huffman_config huffman_config;

// the actual main for this whole package (huffman)
int huffman_main(int argc, char *argv[]);

// parses command line arguments and configures app by creating a huffman_config
huffman_config *parseArgs(int argc, char *argv[]);

// parses the config, gets the relevant file, and outputs the encoded/decoded data
// uses encode/decode
char *huffman_convert(huffman_config *config);

// input: raw data, output: serialized huff file
char *huffman_encode(char *input);

// input: serialized huff file, output: raw data
char *huffman_decode(char *input);

// saves output from input (see: parseArgs and huffman_config) to outputPath
// returns 0 if successful, otherwise 1
int huffman_save(char *input, char *outputPath);

#endif //huffman_h
