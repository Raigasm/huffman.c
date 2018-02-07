#include "string_helpers.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "log.h"

char *sh_getFilename(char *input)
{
  int inputLength = strlen(input);
  log_info("getFilename: %s (length %i)", input, inputLength);
  int size = sizeof(char) * (inputLength + 1);
  // log_info("allocating %i memory", size);
  char *result = malloc(size);
  // log_info("allocated");
  char *savePtr;
  char *inputCopy = malloc(size);
  strcpy(inputCopy, input);
  char *token = strtok(inputCopy, ".");
  log_info("token: %s", token);

  if (strlen(token) > 0)
  {
    strcpy(result, token);
  }
  else
  {
    strcpy(result, "filename");
  }

  return result;
}

char *sh_getExtension(char *input)
{
  int inputLength = strlen(input);
  log_info("getExtension: %s", input);
  int size = sizeof(char) * (inputLength + 1);
  char *result = malloc(size);
  char *filename = sh_getFilename(input);
  int filenameLength = strlen(filename);
  strcpy(result, &input[filenameLength]);
  log_info("extension is %s?", result);
  return result;
}

char *sh_buildFilePath(char *filename, char *extension)
{
  int nameLength, extLength;
  nameLength = strlen(filename);
  extLength = strlen(extension);
  int totalSize = (nameLength + extLength) + 1;                // extra + 1 is for the '.'
  char *result = (char *)malloc(sizeof(char) * totalSize + 1); // need another + 1 to make room for end of string
  strcpy(result, filename);
  if (extLength > 0)
  {
    strcat(result, ".");
    strcat(result, extension);
  }
  return result;
}
