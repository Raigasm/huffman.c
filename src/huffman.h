#ifndef huffman_h
#define huffman_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct huffman_config
{
  char *inPath;  // input data path
  char *in;      // input data
  char *outPath; // output file path
  char *out;     // output data
  int action;    // 0 = not yet determined, 1 = encode (raw -> HUFF), 2 = decode (HUFF -> raw)
} huffman_config;

// the actual main for this whole package (huffman)
int huffman_main(int argc, char *argv[]);

// parses command line arguments and configures app by creating a huffman_config
huffman_config *parseArgs(int argc, char *argv[]);

// input: raw data, output: serialized huff file
// expects:
//  config->action = 1
//  config->inPath = original filename path etc
//  config->in = original file src
//  config->out = space for converted output
//  config->outPath = where to save final file
char *huffman_encode(huffman_config *config);

// input: serialized huff file, output: raw data
// expects:
//  config->action = 2
//  config->inPath = original huff path etc
//  config->in = huff_file->data
//  config->out = space for converted output
//  config->outPath = where to save final file
char *huffman_decode(huffman_config *config);

// parses the config, gets the relevant file, and outputs the encoded/decoded data
// uses encode/decode functions defined above
char *huffman_convert(huffman_config *config);

// saves output from input (see: parseArgs and huffman_config) to outputPath
// returns 0 if successful, otherwise 1
int huffman_save(char *input, char *outputPath);

#endif //huffman_h
