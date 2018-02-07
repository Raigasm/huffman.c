#include "character_frequency.h"
#include <string.h>
#include "log.h"
#include "../lib/parson/parson.h";

int charfreq_indexOf(char input, char *arr)
{
  int result = -1;
  int i = 0;
  while (arr[i] != '\0')
  {
    if (arr[i] == input)
    {
      result = i;
      break;
    }
    i++;
  }
  return result;
}

// creates a charfreq_table
charfreq_table *charfreq_table_create(unsigned long size)
{
  charfreq_table *result = (charfreq_table *)malloc(sizeof(charfreq_table));
  result->character = (char *)malloc(sizeof(char) * size);
  result->frequency = (int *)malloc(sizeof(int) * size);
  return result;
}

charfreq_table *charfreq_generate(char *input)
{
  int length = strlen(input);
  unsigned long size = (unsigned long)length + 1;
  charfreq_table *output = charfreq_table_create(size);
  log_info("generating char_freq_table of length %i", length);
  for (int i = 0; i < length; i++)
  {
    charfreq_process(input[i], output);
  }
  return output;
}

// processes a character into a character frequency array pair
void charfreq_process(char input, charfreq_table *table)
{
  int index = charfreq_indexOf(input, table->character);
  if (index == -1)
  {
    // append to end of array
    int i = 0;
    while (table->character[i] != '\0')
    {
      i++;
    }
    table->character[i] = input;
    table->character[i + 1] = '\0';
    table->frequency[i] = 1;
    // set frequency to 1
  }
  else
  {
    // increment frequency
    table->frequency[index]++;
  }
  return;
}

// produces a stringified json rendering of a given charfreq_table
char *charfreq_print(charfreq_table *table)
{
  JSON_Value *root = json_value_init_object();
  JSON_Object *rootObject = json_value_get_object(root);
  JSON_Value *charactersV = json_value_init_array();
  JSON_Value *frequenciesV = json_value_init_array();
  JSON_Array *characters = json_value_get_array(charactersV);
  JSON_Array *frequencies = json_value_get_array(frequenciesV);
  int length = strlen(table->character);
  char *result = (char *)malloc(1024768);
  for (int i = 0; i < length; i++)
  {
    json_array_append_string(characters, table->character[i]);
    json_array_append_number(frequencies, table->frequency[i]);
  }
  json_object_set_value(rootObject, "character", characters);
  json_object_set_value(rootObject, "frequency", frequencies);
  char *serialized = json_serialize_to_string(root);
  strcpy(result, serialized);
  json_free_serialized_string(serialized);
  json_value_free(root);
  log_info("char_freq_table:\n\n%s", result);
  return result;
}