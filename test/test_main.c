#include "../src/log.h"
#include "../lib/minunit.h"
#include "../src/huffman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tests_run = 0;
int tests_failed = 0;
int suites_run = 0;
int suites_failed = 0;

static char *test_check_testing_works()
{
  mu_assert("Testing does not work", 7 != 7);
  return 0;
}

static char *all_tests()
{
  mu_run_suite(test_check_testing_works);
  return 0;
}

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

int main()
{
  runTests();
}
