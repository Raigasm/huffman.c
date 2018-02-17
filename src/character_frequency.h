#ifndef charfreq_H
#define charfreq_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct charfreq_table
{
    char *character; // an array of characters
    int *frequency;  // an array of frequencies, corresponds to characters
    int n;           // height of table, ie. how many unique characters encoded, ie. strlen(character)
    char **code;
} charfreq_table;

// creates a charfreq_table
charfreq_table *charfreq_table_create();

/*
processes all of input, creating a character frequency table
using countCharacters to update arr and freq
 */
charfreq_table *charfreq_generate(char *input);
int charfreq_code_update(charfreq_table *table, char *code, int digit);
char *charfreq_code_read(charfreq_table *table, char input);

// processes a character into a character frequency array pair
void charfreq_process(char input, charfreq_table *table);

// returns the index of a character in an array
int charfreq_indexOf(char input, char arr[]);

// produces a stringified json rendering of a given charfreq_table
char *charfreq_print(charfreq_table *table);

#endif //charfreq_H
