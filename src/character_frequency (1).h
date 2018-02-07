#ifdef CHARACTER_FREQUENCY_H
#define CHARACTER_FREQUENCY_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct character_frequency_table character_frequency_table;

// processes all of input, using countCharacters to update arr and freq
character_frequency_table *characterFrequency_generate(char *input);

// processes a character into a character frequency table
void countCharacter(char input, character_frequency_table *output);

// returns the index of a character
int characterFrequency_indexOf(char input, char arr[]);

// produces a json string of a given character frequency pair
char *characterFrequency_print(character_frequency_table *input);

#endif //CHARACTER_FREQUENCY_H
