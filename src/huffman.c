#include "huffman.h"
#include "log.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const int HUFFMAN_FILE_MAX_SIZE = 1048576; // max size of input/output files

struct huffman_config
{
  char *inPath;  // input data path
  char *in;      // input data
  char *outPath; // output file path
  char *out;     // output data
  int action;    // 0 = not yet determined, 1 = encode (raw -> HUFF), 2 = decode (HUFF -> raw)
};

int huffman_main(int argc, char *argv[])
{
  // print extra arguments
  printf("huffman_main executed with %i arguments\n\targuments:\n\t\t", (argc - 1));

  int i = 1;
  while (argv[i] != NULL)
  {
    printf("%s ", argv[i++]);
  }
  printf("\n");

  huffman_config *config;
  config = parseArgs(argc, argv);
  convert(config);
  save(config->out, config->outPath);

  return 0;
}

huffman_config *parseArgs(int argc, char *argv[])
{
  printf("parseArgs\n");
  huffman_config *config = (huffman_config *)malloc(sizeof(huffman_config));
  config->inPath = (char *)malloc(256);
  config->in = (char *)malloc(HUFFMAN_FILE_MAX_SIZE); // TODO: determine max size of input and edit config.in initializing
  config->outPath = (char *)malloc(256);
  config->out = (char *)malloc(HUFFMAN_FILE_MAX_SIZE);

  strcpy(config->inPath, "/input/path.txt");
  strcpy(config->outPath, "/output/path.huff");
  strcpy(config->in, "RAW\nRAW\nRAW\nRAW\nRAW\nRAW\nRAW\nRAW\nRAW\nRAW\nRAW\nRAW\nRAW\nRAW\n");
  strcpy(config->out, "CONVERTED\nCONVERTED\nCONVERTED\nCONVERTED\nCONVERTED\nCONVERTED\nCONVERTED\nCONVERTED\nCONVERTED\nCONVERTED\nCONVERTED\nCONVERTED\nCONVERTED\nCONVERTED\n");
  config->action = 1;
  return config;
}

char *convert(huffman_config *config)
{
  printf("huffman_convert:\n\t");
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

int save(char *output, char *outputPath)
{
  printf("huffman_save:\n\tsaving to %s\n", outputPath);
  return 0;
}
