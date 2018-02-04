#include "character-frequency.h"

typedef struct character_frequency_table
{
  char *character; // an array of characters
  int *frequency;  // an array of frequencies, corresponds to characters
} character_frequency_table;
