#ifndef HUFFMAN_FILE_FORMAT
#define HUFFMAN_FILE_FORMAT

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "log.h"
#include "character-frequency.h"
#include "../lib/parson/parson.h"

// xxx

typedef struct character_frequency_table character_frequency_table;

typedef struct huff_meta
{
  char *filename;
  char *extension;
  int size;
} huff_meta;

typedef struct huff_file
{
  huff_meta *meta;
  character_frequency_table *table;
  char *data;
} huff_file;

// reads a huff file from source and stores the content in huff_file
huff_file *HUFF_read(FILE *source, huff_file *output);

// creates a huff_file instance
huff_file *HUFF_create(char *data, huff_file *output);

// saves a huff file to the filesystem
FILE *HUFF_save(huff_file *input, char *path);

// creates a huff_meta instance
huff_meta *HUFF_meta_create(char *filename, char *extension, long size);

// TODO: cleanup memory on huff_meta
// char *HUFF_meta_delete(char *input, char *output);

// serializes a huff_meta into a string, to save
char *HUFF_meta_serialize(huff_meta *input, char *output);

// creates a huff_meta instance from written data
huff_meta *HUFF_meta_deserialize(char *input);

#endif //HUFFMAN_FILE_FORMAT