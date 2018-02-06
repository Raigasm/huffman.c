#ifdef CHARACTER_FREQUENCY_H
#define CHARACTER_FREQUENCY_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// processes all of input, using countCharacters to update arr and freq
void characterFrequency_generate(char *input, char *arr, int freq[]);

// processes a character into a character frequency array pair
void countCharacter(char input, char *arr, int freq[]);

// returns the index of a character
int characterFrequency_indexOf(char input, char arr[]);

// produces a json string of a given character frequency pair
char *characterFrequency_print(char *arr, int freq[]);

#endif //CHARACTER_FREQUENCY_H
