#include "string_helpers.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "log.h"

char *sh_getFilename(char *input)
{
  int inputLength = strlen(input);
  char *result = malloc((sizeof(char) * inputLength + 1));
  char *savePtr;
  char *token = strtok_r(input, ".", &savePtr);

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
  char *result = "lol";

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
