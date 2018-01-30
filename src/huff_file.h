#ifndef HUFFMAN_FILE_FORMAT
#define HUFFMAN_FILE_FORMAT

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char *HUF_read(char *source, char *output);
char *HUF_generate(char *input, char *output);

char *HUFmeta_create(char *input, char *output);
char *HUFmeta_delete(char *input, char *output);
char *HUF_meta_serialize(char *input, char *output);
char *HUF_meta_deserialize(char *input, char *ouput);

#endif //HUFFMAN_FILE_FORMAT