#include "log.h"
#include "huff_file.h"
#include "character-frequency.h"

huff_meta *HUFF_meta_create(char *filename, char *extension, int size)
{
  log_info("creating meta file for %s.%s (%i)", filename, extension, size);
  huff_meta *output = malloc(sizeof(huff_meta));
  output->filename = malloc(strlen(filename) + 1);
  output->extension = malloc(strlen(extension) + 1);
  strcpy(filename, output->filename);
  strcpy(filename, output->extension);
  output->size = size;

  return output;
}