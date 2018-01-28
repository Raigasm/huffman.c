#ifdef CHARACTER_FREQUENCY_H
#define CHARACTER_FREQUENCY_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void characterFrequency_generate(char *input, char *arr, int freq[]);
void characterFrequency_print(char *arr, int freq[]);
void countCharacter(char input, char *arr, int freq[]);

#endif //CHARACTER_FREQUENCY_H
