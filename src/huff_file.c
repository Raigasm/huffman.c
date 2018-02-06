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
  JSON_Value *root_value = json_value_init_object();
  JSON_Object *root_object = json_value_get_object(root_value);
  char *serialized_string = NULL;
  json_object_dotset_string(root_object, "meta.filename", input->meta->filename);
  json_object_dotset_string(root_object, "meta.extension", input->meta->extension);
  json_object_dotset_number(root_object, "meta.size", input->meta->size);
  json_object_set_string(root_object, "data", input->data);
  serialized_string = json_serialize_to_string(root_value);

  // save to path
  const char *fileMode = "w+";
  FILE *output = fopen(path, fileMode);
  fprintf(output, "%s", serialized_string);

  // clean up and report
  json_free_serialized_string(serialized_string);
  json_value_free(root_value);
  fclose(output);
  log_info("HUFF file created at %s", path);
}

// reads a huff file from source and stores the content in huff_file
// uses JSON library parson
huff_file *HUFF_read(char *source)
{
  log_info("reading %s", source);
  // get contents of source and store to buffer
  FILE *src = fopen(source, "r");
  char buffer[1024768]; // TODO: figure out what i should set this to
  fgets(buffer, 1024767, src);

  log_info("found file:\n\n%s\n\nparsing json...", buffer);
  // parse json and create huff object.
  JSON_Value *parsed = json_parse_string(buffer);
  JSON_Object *parsedObject = json_value_get_object(parsed);

  const char *metaFilename = json_object_dotget_string(parsedObject, "meta.filename");
  const char *metaExtension = json_object_dotget_string(parsedObject, "meta.extension");
  unsigned long metaSize = json_object_dotget_number(parsedObject, "meta.size");
  const char *data = json_object_get_string(parsedObject, "data");

  log_info("creating a huff_file, %s %s (%ul)\n\t%s", metaFilename, metaExtension, metaSize, data);
  huff_meta *meta = HUFF_meta_create((char *)metaFilename, (char *)metaExtension, metaSize);
  huff_file *output = HUFF_create(meta, (char *)data);
  fclose(src);
  return output;
}
