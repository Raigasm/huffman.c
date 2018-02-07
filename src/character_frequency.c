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
