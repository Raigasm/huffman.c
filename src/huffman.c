#include "huffman.h"
#include "string_helpers.h"
#include "log.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const int HUFFMAN_FILE_MAX_SIZE = 1048576; // max size of input/output files

int huffman_main(int argc, char *argv[])
{
  // print extra arguments
  log_debug("huffman_main executed with %i arguments: %s %s", (argc - 1), argv[1], argv[2]);

  huffman_config *config = parseArgs(argc, argv);
  char *output = huffman_convert(config);
  int result = huffman_save(output, config->outPath);
  if (result != 0)
  {
    log_error("huffman_save failed with error code %i", result);
  }
  else
  {
    log_info("codec execution succeeded.");
  }
  return result;
}

huffman_config *parseArgs(int argc, char *argv[])
{
  if (argc == 1)
  {
    log_error("Usage: huffman-codec <src> <output>");
    log_error("PLEASE NOTE: no input of greater size than %i can be used", HUFFMAN_FILE_MAX_SIZE);
    return (huffman_config *)0;
  }
  else if (argc >= 2)
  {
    // we at least have the src now
    char *inputPath = argv[1];
    char *outputPath;
    if (argc == 3)
    {
      outputPath = argv[2];
    }
    else
    {
      outputPath = "output.txt";
    }

    huffman_config *result = (huffman_config *)malloc(sizeof(huffman_config));
    result->in = malloc(HUFFMAN_FILE_MAX_SIZE);
    result->inPath = (char *)malloc(256);
    strcpy(result->inPath, inputPath);
    result->outPath = (char *)malloc(256);
    strcpy(result->outPath, outputPath);
    result->out = (char *)malloc(HUFFMAN_FILE_MAX_SIZE);
    log_debug("parseArgs:\tin: %s\tout:%s", result->inPath, result->outPath);
    char *originalExtension = sh_getExtension(inputPath);
    int action;
    if (strcmp(originalExtension, "huff") == 0)
    { // input was a huff file, lets decode
      log_info("huff file detected, decoding");
      action = 2;
    }
    else
    {
      log_info("non-huff file detected, encoding");
      action = 1;
    }
    result->action = action;
    log_info("parseArgs finished:\npaths:\taction: %i\tin: %s\tout: %s\nin: %s", action, result->inPath, result->outPath, result->in);
    return result;
  }
}

char *huffman_convert(huffman_config *config)
{
  log_debug("huffman_convert");

  printf("\t  ");
  switch (config->action)
  {
  case 0:
    printf("ERROR");
    break;
  case 1:
    printf("ENCODING");
    break;
  case 2:
    printf("DECODING");
    break;
  default:
    printf("??????????");
    // TODO: throw exception
    break;
  }

  printf(" %s -> %s\n", config->inPath, config->outPath);
  return 0;
}

// input: raw data, output: serialized huff file
char *huffman_encode(huffman_config *config)
{
  log_info("huffman_encode - processing %i characters", strlen(config->in));
}

// input: serialized huff file, output: raw data
char *huffman_decode(huffman_config *config)
{
  log_info("huffman_decode - processing %i characters", strlen(config->in));
}

int huffman_save(char *output, char *outputPath)
{
  log_debug("huffman_save:\tsaving to %s\n", outputPath);
  return 0;
}
