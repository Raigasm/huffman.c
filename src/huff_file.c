#include "log.h"
#include "huff_file.h"
#include "character-frequency.h"
#include "../lib/parson/parson.h"

huff_meta *HUFF_meta_create(char *filename, char *extension, long size)
{
  log_info("creating meta file for %s.%s (%i)", filename, extension, size);
  huff_meta *output = malloc(sizeof(huff_meta));
  output->filename = malloc(strlen(filename) + 1);
  output->extension = malloc(strlen(extension) + 1);
  strcpy(output->filename, filename);
  strcpy(output->extension, extension);
  output->size = size;

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