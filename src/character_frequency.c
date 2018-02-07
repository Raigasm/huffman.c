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
  JSON_Value *tableJSON = json_parse_string("{\"character\":[],\"frequency\":[]}");
  JSON_Object *tableObject = json_value_get_object(tableJSON);
  JSON_Array *characters = json_object_get_array(tableObject, "character");
  JSON_Array *freqs = json_object_get_array(tableObject, "frequency");

  log_info("json object created");

  int i = 0;
  log_info("table->character[0] = %c", table->character[0]);
  while (table->character[i] != '\0')
  {
    char buffer[2];
    sprintf(buffer, "%c", table->character[i]);
    json_array_append_string(characters, buffer);
    json_array_append_number(freqs, table->frequency[i]);
    log_info("+ ['%c',%i]", table->character[i], table->frequency[i]);
    i++;
  }
  log_info("finished iteration. %i character frequencies processed.", i);

  char *output = json_serialize_to_string(tableJSON);
  log_info("output: %s", output);
  return output;
}
