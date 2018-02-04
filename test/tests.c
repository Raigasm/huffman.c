#include "../src/log.h"
#include "../lib/minunit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 
 * Module Test Files
 **/
#include "../src/huffman.h"
#include "../src/min-heap.h"
#include "../src/character-frequency.h"
#include "../src/huff_file.h"

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

/**
 * src/huffman.c 
 **/

/** 
 * ../src/huffman.h 
 **/
static char *test_huffman()
{
  log_info("test_huffman test start");
  mu_assert("test_huffman not implemented", 0);
}

/** 
 * ../src/min-heap.h 
 **/
static char *test_min_heap()
{
  log_info("test_min_heap test start");
  mu_assert("test_min_heap not implemented", 0);
}

/** 
 * ../src/character-frequency.h 
 **/
static char *test_character_frequency()
{
  log_info("test_character_frequency test start");
  mu_assert("test_character_frequency not implemented", 0);
}

/** 
 * ../src/huff_file.h 
 **/
static char *test_huff_file()
{
  log_info("test_huff_file test start");
  mu_assert("test_huff_file not implemented", 0);
}

// TODO: Complete list of tests
static char *all_tests() ///
{
  mu_run_suite(test_check_testing_works);
  mu_run_suite(test_huffman);
  mu_run_suite(test_huffman);
  mu_run_suite(test_min_heap);
  mu_run_suite(test_character_frequency);
  mu_run_suite(test_huff_file);

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
