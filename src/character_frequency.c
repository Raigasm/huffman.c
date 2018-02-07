#include "character_frequency.h"

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

charfreq_table *charfreq_generate(char *input)
{
  return (charfreq_table *)0;
}

// processes a character into a character frequency array pair
void charfreq_process(char input, charfreq_table *table)
{
  return;
}

// produces a stringified json rendering of a given charfreq_table
char *charfreq_print(charfreq_table *table)
{
  return (char *)0;
}