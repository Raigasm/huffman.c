#ifndef huffman_h
#define huffman_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct huffman_config huffman_config;

// the actual main for this package
int huffman_main(int argc, char *argv[]);

// parses command line arguments and configures app
huffman_config *parseArgs(int argc, char *argv[]);

// reers to the config, gets the relevant file, and outputs the encoded/decoded data
char *convert(huffman_config *config);

// saves output from config to outputPath
int save(char *output, char *outputPath);

#endif //huffman_h
