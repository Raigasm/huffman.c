#include "log.h"
#include "huff_file.h"
#include "character-frequency.h"
#include "../lib/parson/parson.h"
#include <string.h>

huff_meta *HUFF_meta_create(char *filename, char *extension, unsigned long size)
{
  log_info("creating meta file for %s.%s (%ld)", filename, extension, size);
  huff_meta *output = malloc(sizeof(huff_meta));
  output->filename = malloc(strlen(filename) + 1);
  output->extension = malloc(strlen(extension) + 1);
  strcpy(output->filename, filename);
  strcpy(output->extension, extension);
  output->size = (unsigned long)size;

  return output;
}

char *HUFF_meta_serialize(huff_meta *input, char *output)
{
  log_info(">>HUFF_meta_serialize");

  JSON_Value *root_value = json_value_init_object();
  JSON_Object *root_object = json_value_get_object(root_value);
  char *serialized_string = NULL;
  json_object_dotset_string(root_object, "meta.filename", input->filename);
  json_object_dotset_string(root_object, "meta.extension", input->extension);
  json_object_dotset_number(root_object, "meta.size", input->size);
  serialized_string = json_serialize_to_string(root_value);
  strcpy(output, serialized_string);
  json_free_serialized_string(serialized_string);
  json_value_free(root_value);

  return output;
}

huff_meta *HUFF_meta_deserialize(char *input)
{
  log_info(">>HUFF_meta_deserialize");

  JSON_Value *metaValue = json_parse_string_with_comments(input);
  JSON_Object *metaObject = json_value_get_object(metaValue);
  const char *filename = json_object_dotget_string(metaObject, "meta.filename");
  const char *extension = json_object_dotget_string(metaObject, "meta.extension");
  unsigned long size = (unsigned long)json_object_dotget_number(metaObject, "meta.size");
  huff_meta *output = HUFF_meta_create((char *)filename, (char *)extension, size);
  return output;
}

/**
 * typedef struct huff_file
 * {
  huff_meta *meta;
  character_frequency_table *table;
  char *data;
* } huff_file;
**/

// creates a huff_file instance from a given huff_meta and data
huff_file *HUFF_create(huff_meta *meta, char *data)
{

  log_info("creating huff_file object");

  huff_file *output = malloc(sizeof(huff_file));

  output->meta = meta;
  output->data = data;

  return output;
}

// saves a huff file to the filesystem at the given path
void HUFF_write(huff_file *input, char *path)
{
  // serialize input to JSON
  const char *serialized = "blah blah blah\n";

  // save to path
  const char *fileMode = "w+";
  FILE *output = fopen(path, fileMode);
  fprintf(output, serialized);
  fclose(output);
  log_info("HUFF file created at %s", path);
}