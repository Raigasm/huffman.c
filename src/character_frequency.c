#include "character_frequency.h"

typedef struct character_frequency_table
{
  char *character; // an array of characters
  int *frequency;  // an array of frequencies, corresponds to characters
} character_frequency_table;

int characterFrequency_indexOf(char input, char *arr)
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
