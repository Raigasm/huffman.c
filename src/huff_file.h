#ifndef HUFFMAN_FILE_FORMAT
#define HUFFMAN_FILE_FORMAT

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "log.h"
#include "character-frequency.h"
#include "../lib/parson/parson.h"

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

// creates a huff_file instance
huff_file *HUFF_create(huff_meta *meta, char *data);

// saves a huff file to the filesystem
void HUFF_write(huff_file *input, char *path);

// reads a huff file from a path (source) and constructs a corresponding huff_file instance
// uses JSON library parson
huff_file *HUFF_read(char *source);

// creates a huff_meta instance
huff_meta *HUFF_meta_create(char *filename, char *extension, unsigned long size);

// TODO: cleanup memory on huff_meta
// char *HUFF_meta_delete(char *input, char *output);

// serializes a huff_meta into a string, to save
char *HUFF_meta_serialize(huff_meta *input, char *output);

// creates a huff_meta instance from written data
huff_meta *HUFF_meta_deserialize(char *input);

#endif //HUFFMAN_FILE_FORMAT
