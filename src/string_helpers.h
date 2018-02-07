#ifndef STRING_HELPERS_H
#define STRING_HELPERS_H
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "log.h"

char *sh_getFilename(char *input);
char *sh_getExtension(char *input);
char *sh_buildFilePath(char *filename, char *extension);

#endif // STRING_HELPERS_H
