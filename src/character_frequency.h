#ifndef charfreq_H
#define charfreq_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct charfreq_table
{
    char *character; // an array of characters
    int *frequency;  // an array of frequencies, corresponds to characters
} charfreq_table;

/* 
processes all of input, creating a character frequency table
using countCharacters to update arr and freq
 */
charfreq_table *charfreq_generate(char *input);

// processes a character into a character frequency array pair
void countCharacter(char input, charfreq_table *table);

// returns the index of a character in an array
int charfreq_indexOf(char input, char arr[]);

// produces a stringified json rendering of a given charfreq_table
char *charfreq_print(charfreq_table *table);

#endif //charfreq_H
