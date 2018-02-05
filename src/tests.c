#include "log.h"
#include "../lib/minunit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 
 * Module Test Files
 **/
#include "huffman.h"
#include "min-heap.h"
#include "character-frequency.h"
#include "huff_file.h"

// Tracking Globals
int tests_run = 0;
int tests_failed = 0;
int suites_run = 0;
int suites_failed = 0;

// Quick check
static char *test_check_testing_works()
{
  mu_assert("Testing does not work", 7 == 7);
  return 0;
}

/**  TODO: huff_file.h tests
 * ../src/huff_file.h 
 **/
static char *test_HUFF_read()
{
  log_info("> test/test_HUFF_read");
  mu_assert("test_HUFF_read not yet implemented", 0);
}
static char *test_HUFF_create()
{
  log_info("> test/test_HUFF_create");
  mu_assert("test_HUFF_create not yet implemented", 0);
}

static char *test_HUFF_save()
{
  log_info("> test/test_HUFF_save");
  mu_assert("test_HUFF_save not yet implemented", 0);
}

static char *test_HUFF_meta_create()
{
  log_info("> test/test_HUFF_meta_create");
  huff_meta *meta = HUFF_meta_create("foo", "bar", 10241024);
  mu_assert("huff_meta_create should create a huff meta instance", meta != NULL);
  mu_assert("huff_meta_create should set filename", strcmp("foo", meta->filename) == 0);
  mu_assert("huff_meta_create should set extension", strcmp("bar", meta->extension) == 0);
  mu_assert("huff_meta_create should set size", meta->size == 10241024);
  return (char *)0;
}
// static char *test_HUFF_meta_delete()
// {
//   log_info("> test/test_HUFF_meta_delete");
//   mu_assert("test_HUFF_meta_delete not yet implemented", 0);
// }
static char *test_HUFF_meta_serialize()
{
  log_info("> test/test_HUFF_meta_serialize");

  /**
   *  We want serialize to be able to take the huff meta with properties:
   *  filename: "bar"
   *  extension: "foo"
   *  size: 10241024 
   *  into a json object
   * 
   *  {
   *   "meta": {
   *     "filename": "bar",
   *     "extension": "foo", 
   *     "size": 10241024
   *   }
   * }
   * 
   **/

  huff_meta *meta = HUFF_meta_create("bar", "foo", 10241024);
  char output[1024];
  HUFF_meta_serialize(meta, output);
  char *expected = "{\"meta\":{\"filename\":\"bar\",\"extension\":\"foo\",\"size\":10241024}}";
  bool match = strcmp(expected, output) == 0;
  if (!match)
  {
    log_error("ERROR: expected\n%s\n\nactual\n%s", expected, output);
  }
  mu_assert("meta_serialize should serialize", match);
  return (char *)0;
}
static char *test_HUFF_meta_deserialize()
{
  /** now we take the json and try and get a huff_meta out of it)
   **/
  huff_meta *meta = HUFF_meta_deserialize("{\"meta\":{\"filename\":\"bar2\",\"extension\":\"foo2\",\"size\":123}}");
  mu_assert("deserialize: filename", strcmp(meta->filename, "bar2") == 0);
  mu_assert("deserialize: extension", strcmp(meta->extension, "foo2") == 0);
  mu_assert("deserialize: size", meta->size == 123);
  return 0;
}

static char *test_huff_file()
{
  mu_run_suite(test_HUFF_meta_create);
  // mu_run_suite(test_HUFF_meta_delete);
  mu_run_suite(test_HUFF_meta_serialize);
  mu_run_suite(test_HUFF_meta_deserialize);
  mu_run_suite(test_HUFF_read);
  mu_run_suite(test_HUFF_create);
  mu_run_suite(test_HUFF_save);
  return (char *)0;
}

/**  TODO: min-heap.h tests
 * ../src/min-heap.h 
 **/
static char *test_min_heap()
{
  log_info("test_min_heap test start");
  mu_assert("test_min_heap not implemented", 0);
}

/**  TODO: character-frequency.h tests
 * ../src/character-frequency.h 
 **/
static char *test_character_frequency()
{
  log_info("test_character_frequency test start");
  mu_assert("test_character_frequency not implemented", 0);
}

/**  TODO: huffman.h tests
 * ../src/huffman.h 
 **/
static char *test_parseArgs()
{
  mu_assert("test_parseArgs not yet implemented", 0);
}

static char *test_convert()
{
  mu_assert("test_conver not yet implemented", 0);
}

static char *test_save()
{
  mu_assert("test_sav not yet implemented", 0);
}

static char *test_huffman()
{
  log_info("test_huffman test start");
  mu_run_suite(test_parseArgs);
  mu_run_suite(test_convert);
  mu_run_suite(test_save);
  mu_assert("test_huffman not implemented", 0);
}

// TODO: Complete list of tests
static char *all_tests() ///
{
  mu_run_suite(test_check_testing_works);
  mu_run_suite(test_huff_file);
  mu_run_suite(test_min_heap);
  mu_run_suite(test_character_frequency);
  mu_run_suite(test_huffman);

  return 0;
}

// Runs all tests
int runTests()
{
  char *result = all_tests();

  if (result != 0)
  {
    printf("FAIL: %s\n", result);
  }
  else
  {
    printf("ALL TESTS PASSED\n");
  }
  printf("%i tests passed.\n", tests_run - tests_failed);

  return tests_run - tests_failed;
}
int main() { return runTests(); }
