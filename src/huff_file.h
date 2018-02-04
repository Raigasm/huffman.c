#ifndef HUFFMAN_FILE_FORMAT
#define HUFFMAN_FILE_FORMAT

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct huff_meta huff_meta;
typedef struct huff_file huff_file;

char *HUFF_read(FILE *source, char *output);

char *HUFF_generate(char *input, char *output);

char *HUFF_meta_create(char *input, char *output);
char *HUFF_meta_delete(char *input, char *output);
char *HUFF_meta_serialize(char *input, char *output);
char *HUFF_meta_deserialize(char *input, char *ouput);

#endif //HUFFMAN_FILE_FORMAT