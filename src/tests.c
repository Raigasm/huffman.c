#include "log.h"
#include "../lib/minunit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Module Test Files
 **/
#include "huffman.h"
#include "min_heap.h"
#include "character_frequency.h"
#include "huff_file.h"
#include "string_helpers.h"

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

static char *test_sh_getFilename()
{
  log_info("test_sh_getFilename start");
  char *exampleA = "foobar.txt";
  char *exampleB = "foobar.tar.gz";
  char *exampleC = "badexample.";
  char *exampleD = "./badexample";

  char *resultA = sh_getFilename(exampleA); // TODO: check
  char *resultB = sh_getFilename(exampleB);
  char *resultC = sh_getFilename(exampleC);
  char *resultD = sh_getFilename(exampleD);

  char *expectedA = "foobar";
  char *expectedB = "foobar";
  char *expectedC = "badexample";
  char *expectedD = "/badexample";

  if (strcmp(resultA, expectedA) != 0)
  {
    log_error("example A - exp: %s\tgot: %s", expectedA, resultA);
  }
  mu_assert("getFilename: failed for example A", strcmp(resultA, expectedA) == 0);

  if (strcmp(resultB, expectedB) != 0)
  {
    log_error("example B - exp: %s\tgot: %s", expectedB, resultB);
  }
  mu_assert("getFilename: failed for example B", strcmp(resultB, expectedB) == 0);

  if (strcmp(resultC, expectedC) != 0)
  {
    log_error("example C - exp: %s\tgot: %s", expectedC, resultC);
  }
  mu_assert("getFilename: failed for example C", strcmp(resultC, expectedC) == 0);

  if (strcmp(resultD, expectedD) != 0)
  {
    log_error("example D - exp: %s\tgot: %s", expectedD, resultD);
  }
  mu_assert("getFilename: failed for example D", strcmp(resultD, expectedD) == 0);

  return (char *)0;
}

static char *test_sh_getExtension()
{
  char *exampleA = "foobar.txt";
  char *exampleB = "foobar.tar.gz";
  char *exampleC = "badexample.";
  char *exampleD = "./badexample";

  char *resultA = sh_getExtension(exampleA); // TODO: check
  char *resultB = sh_getExtension(exampleB);
  char *resultC = sh_getExtension(exampleC);
  char *resultD = sh_getExtension(exampleD);

  char *expectedA = "txt";
  char *expectedB = "tar.gz";
  char *expectedC = "\0";
  char *expectedD = "\0";

  if (strcmp(resultA, expectedA) != 0)
  {
    log_error("example A - exp: %s\tgot: %s", expectedA, resultA);
  }
  mu_assert("getExtension: failed for example A", strcmp(resultA, expectedA) == 0);

  if (strcmp(resultB, expectedB) != 0)
  {
    log_error("example B - exp: %s\tgot: %s", expectedB, resultB);
  }
  mu_assert("getExtension: failed for example B", strcmp(resultB, expectedB) == 0);

  if (strcmp(resultC, expectedC) != 0)
  {
    log_error("example C - exp: %s\tgot: %s", expectedC, resultC);
  }
  mu_assert("getExtension: failed for example C", strcmp(resultC, expectedC) == 0);

  if (strcmp(resultD, expectedD) != 0)
  {
    log_error("example D - exp: %s\tgot: %s", expectedD, resultD);
  }
  mu_assert("getExtension: failed for example D", strcmp(resultD, expectedD) == 0);

  return (char *)0;
}

static char *test_sh_buildFilePath()
{
  char *result = sh_buildFilePath("foobar", "tar.gz");
  char *result2 = sh_buildFilePath("noobar", "\0");
  if (strcmp(result, "foobar.tar.gz") != 0)
  {
    log_error("expected %s, got %s", "foobar.tar.gz", result);
  }
  if (strcmp(result2, "noobar") != 0)
  {
    log_error("expected %s, got %s", "noobar", result);
  }
  mu_assert("buildFilePath should build a filename (1)", strcmp(result, "foobar.tar.gz") == 0);
  mu_assert("buildFilePath should build a filename (2)", strcmp(result2, "noobar") == 0);
  return (char *)0;
}

static char *test_string_helpers()
{
  mu_run_suite(test_sh_buildFilePath);
  mu_run_suite(test_sh_getFilename);
  mu_run_suite(test_sh_getExtension);
  return (char *)0;
}

/**  TODO: huff_file.h tests
 * ../src/huff_file.h
 **/

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
   *
   *  into a json object
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

static char *test_HUFF_create()
{
  log_info("> test/test_HUFF_create");

  // create a meta
  huff_meta *meta = HUFF_meta_create("foobar", "txt", 13371337);
  // fake data string
  char *data = "loremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsum";
  // create huff
  huff_file *huff = HUFF_create(meta, data);
  // check meta
  huff_meta *meta_reference = huff->meta;
  mu_assert("huff_create: meta should have same filename", strcmp(meta_reference->filename, "foobar") == 0);
  mu_assert("huff_create: meta should have same extension", strcmp(meta_reference->extension, "txt") == 0);
  mu_assert("huff_create: meta should have same size", meta_reference->size == 13371337);

  // check data
  mu_assert("huff_create: meta should have same data", strcmp(huff->data, data) == 0);

  return (char *)0;
}

static char *test_HUFF_write()
{
  log_info("> test/test_HUFF_write");

  // create a meta
  huff_meta *meta = HUFF_meta_create("foobar", "txt", 13371337);
  // fake data string
  char *data = "loremipsum";
  // create huff
  huff_file *huff = HUFF_create(meta, data);

  // save to root directory as 'test.huff'
  char *filename = "test.huff";
  HUFF_write(huff, filename);
  FILE *fp = fopen(filename, "r");
  char buffer[1024768];
  fgets(buffer, 1024768, fp);
  // TODO: check file contents
  // delete the file now that we are done
  fclose(fp);
  remove(filename);

  mu_assert("test_HUFF_write not yet implemented", 1);
  return (char *)0;
}

static char *test_HUFF_read()
{
  log_info("> test/test_HUFF_read");

  // create a meta
  huff_meta *meta = HUFF_meta_create("foobar", "txt", 13371337);
  // fake data string
  char *data = "loremipsum";
  // create huff
  huff_file *huff = HUFF_create(meta, data);

  // save to root directory as 'test2.huff'
  char *filename = "test2.huff";
  HUFF_write(huff, filename);
  FILE *fp = fopen(filename, "r");
  char buffer[1024768];
  fgets(buffer, 1024768, fp);

  // now we try to read it
  huff_file *contents = HUFF_read("test2.huff");

  mu_assert("huff_read should match meta filename", strcmp(contents->meta->filename, meta->filename) == 0);
  mu_assert("huff_read should match meta extension", strcmp(contents->meta->extension, meta->extension) == 0);
  mu_assert("huff_read should match data", strcmp(contents->data, data) == 0);
  mu_assert("huff_read should match size", contents->meta->size == 13371337);

  // delete the file now that we are done
  fclose(fp);
  remove(filename);

  mu_assert("test_HUFF_read not yet implemented", 1);
  return (char *)0;
}

static char *test_huff_file()
{
  mu_run_suite(test_HUFF_meta_create);
  // mu_run_suite(test_HUFF_meta_delete); TODO: test_huff_meta_delete
  mu_run_suite(test_HUFF_meta_serialize);
  mu_run_suite(test_HUFF_meta_deserialize);
  mu_run_suite(test_HUFF_create);
  mu_run_suite(test_HUFF_write);
  mu_run_suite(test_HUFF_read);
  return (char *)0;
}

/**  TODO: min-heap.h tests
 * ../src/min-heap.h
 **/

// minheap *minHeap_create(int capacity);
static char *test_minHeap_create()
{
  log_info("minHeap_create start");
  minheap *result = minHeap_create(1337);
  mu_assert("minHeap_create creates correct size", result->size == 0);
  mu_assert("minHeap_create creates correct capacity", result->capacity == 1337);
  return (char *)0;
}

// minheap *minHeap_build(minheap *minHeap);
static char *test_minHeap_build()
{
  log_info("minHeap_build start");
  mu_assert("minHeap_build implemented", 1);
  return (char *)0;
}

// node *minHeap_getMinNode(minheap *minHeap);
static char *test_minHeap_getMinNode()
{
  log_info("minHeap_getMinNode start");
  mu_assert("minHeap_getMinNode implemented", 1);
  return (char *)0;
}

// bool minHeap_hasOnlyOne(minheap *minHeap);
static char *test_minHeap_hasOnlyOne()
{
  log_info("minHeap_hasOnlyOne start");
  minheap *shouldBeTrue = minHeap_create(100);
  shouldBeTrue->size = 1;
  minheap *shouldBeFalse = minHeap_create(100);
  shouldBeFalse->size = 3;

  mu_assert("minHeap_hasOnlyOne can detect singleton nodes properly", minHeap_hasOnlyOne(shouldBeTrue) == true);
  mu_assert("minHeap_hasOnlyOne can detect populated heaps", minHeap_hasOnlyOne(shouldBeFalse) == false);
  return (char *)0;
}

// void minHeap_minHeapify(struct minheap *minHeap, int index);
static char *test_minHeap_minHeapify()
{
  log_info("minHeap_minHeapify start");
  mu_assert("minHeap_minHeapify implemented", 1);
}

// node *node_create(char data, int freq);
static char *test_node_create()
{
  log_info("node_create start");
  /*  Test nodes:
    node testNodeA {character: ['a'], [1]}
   */

  node *testNode = node_create('a', 1);
  mu_assert("node_create creates node with appropriate character", testNode->data = 'a');
  mu_assert("node_create creates node with appropriate frequency", testNode->frequency = 1);
  return (char *)0;
}

// bool node_isLeaf(node *input);
static char *test_node_isLeaf()
{
  log_info("node_isLeaf start");
  // example leaf
  node *leaf = node_create('a', 42);
  mu_assert("isLeaf should return true if node has no children", node_isLeaf(leaf));
  // not a leaf (1 child)
  node *hasChild = node_create('b', 15);
  node *hasChildAlso = node_create('c', 21);
  hasChild->lt = leaf;
  hasChildAlso->rt = leaf;
  mu_assert("isLeaf should return false if node has a child", !node_isLeaf(hasChild));
  mu_assert("isLeaf should return false if node has a child (also)", !node_isLeaf(hasChildAlso));
  // not a leaf (2 children)
  node *hasChildren = node_create('d', 3);
  hasChildren->lt = hasChild;
  hasChildren->rt = hasChildAlso;
  bool finalResult = node_isLeaf(hasChildren);
  log_info("finalResult is %i", finalResult);
  mu_assert("if not a leaf node, isLeaf should return false", finalResult == false);
  mu_assert("node_isLeaf implemented", 1);
  return (char *)0;
}

// void node_add(minheap *heap, node *input);
static char *test_node_add()
{
  log_info("node_add start");
  mu_assert("node_add implemented", 1);
  return (char *)0;
}

static char *test_min_heap()
{
  log_info("test_min_heap test start");
  mu_run_suite(test_node_create);
  mu_run_suite(test_node_isLeaf);
  mu_run_suite(test_minHeap_create);
  mu_run_suite(test_minHeap_hasOnlyOne);
  mu_run_suite(test_minHeap_getMinNode);
  mu_run_suite(test_minHeap_minHeapify);
  mu_run_suite(test_node_add);      // TODO: node_add test
  mu_run_suite(test_minHeap_build); // TODO: test_minHeap_build
  mu_assert("test_min_heap not implemented", 1);
  return (char *)0;
}

/**  TODO: character-frequency.h tests
 * ../src/character-frequency.h
 **/
// void charfreq_generate(char *input, char *arr, int freq[]);
static char *test_charfreq_generate()
{
  log_info("TEST: charfreq_generate implemented", 0);
  /** TEST DATA:
  * raw: 'aaaabbbccd'
  * characters: ['a','b','c','d']
  * frequencies: [4,3,2,1]
  **/

  // make a table
  charfreq_table *table = charfreq_generate("aaaabbbccd");
  mu_assert("charfreq_generate has correct 'a' index", table->character[0] == 'a');
  mu_assert("charfreq_generate has correct 'b' index", table->character[1] == 'b');
  mu_assert("charfreq_generate has correct 'd' index", table->character[3] == 'd');
  mu_assert("charfreq_generate has correct 'c' index", table->character[2] == 'c');
  mu_assert("charfreq_generate has correct 'a' frequency", table->frequency[0] == 4);
  mu_assert("charfreq_generate has correct 'b' frequency", table->frequency[1] == 3);
  mu_assert("charfreq_generate has correct 'c' frequency", table->frequency[2] == 2);
  mu_assert("charfreq_generate has correct 'd' frequency", table->frequency[3] == 1);
  mu_assert("charfreq_generate implemented", 1);
  return (char *)0;
}
// void charfreq_print(char *arr, int freq[]);
static char *test_charfreq_print()
{
  log_info("TEST: charfreq_print");
  /** TEST DATA:
  * raw: 'aaaabbbccd'
  * characters: ['a','b','c','d']
  * frequencies: [4,3,2,1]
  **/

  // make a table
  charfreq_table *table = charfreq_generate("aaaabbbccd");
  char *output = charfreq_print(table);
  char *expected = "{\"character\":[\"a\",\"b\",\"c\",\"d\"],\"frequency\":[4,3,2,1]}";
  bool match = strcmp(expected, output) == 0;
  if (!match)
  {
    log_error("ERROR: expected\n%s\n\nactual\n%s", expected, output);
  }

  mu_assert("charfreq_print implemented", match);
  return (char *)0;
}

static char *test_indexOf()
{
  log_info("TEST: indexOf");
  char input[6] = {'a', 'b', 'c', 'd', 'e', ' '};
  mu_assert("indexOf implemented 'a'", charfreq_indexOf('e', input) == 4);
  mu_assert("indexOf implemented ' '", charfreq_indexOf(' ', input) == 5);
  return (char *)0;
}

// void charfreq_process(char input, charfreq_table *table);
static char *test_charfreq_process()
{
  log_info("TEST: charfreq_process");
  /** TEST DATA:
  * raw: 'aaaabbbccd'
  * characters: ['a','b','c','d']
  * frequencies: [4,3,2,1]
  **/

  // make a table
  charfreq_table *table = charfreq_table_create(4);
  charfreq_process('a', table);
  charfreq_process('a', table);
  charfreq_process('a', table);
  charfreq_process('a', table);
  charfreq_process('b', table);
  charfreq_process('b', table);
  charfreq_process('b', table);
  charfreq_process('c', table);
  charfreq_process('c', table);
  charfreq_process('d', table);
  mu_assert("charfreq_process has correct 'a' index", table->character[0] == 'a');
  mu_assert("charfreq_process has correct 'b' index", table->character[1] == 'b');
  mu_assert("charfreq_process has correct 'd' index", table->character[3] == 'd');
  mu_assert("charfreq_process has correct 'c' index", table->character[2] == 'c');
  mu_assert("charfreq_process has correct 'a' frequency", table->frequency[0] == 4);
  mu_assert("charfreq_process has correct 'b' frequency", table->frequency[1] == 3);
  mu_assert("charfreq_process has correct 'c' frequency", table->frequency[2] == 2);
  mu_assert("charfreq_process has correct 'd' frequency", table->frequency[3] == 1);
  mu_assert("charfreq_process implemented", 1);
  return (char *)0;
}

static char *test_character_frequency()
{
  log_info("test_character_frequency test start");
  mu_run_suite(test_indexOf);
  mu_run_suite(test_charfreq_process);
  mu_run_suite(test_charfreq_generate);
  mu_run_suite(test_charfreq_print);
  mu_assert("test_character_frequency implemented", 1);
  return (char *)0;
}

/**  TODO: huffman.h tests
 * ../src/huffman.h
 **/
static char *test_parseArgs()
{
  int nArgs = 3;
  char *allArgsA[] = {"huffman-codec", "foobar.txt", "foobar.huff"};
  char *allArgsB[] = {"huffman-codec", "foobar.huff", "foobar.txt"};
  huffman_config *resultA = parseArgs(nArgs, allArgsA);
  huffman_config *resultB = parseArgs(nArgs, allArgsB);

  mu_assert("parseArgs should handle txt input (in path)", strcmp(resultA->inPath, "foobar.txt") == 0);
  mu_assert("parseArgs should handle txt input (out path)", strcmp(resultA->outPath, "foobar.huff") == 0);
  mu_assert("parseArgs should handle txt input (action)", resultA->action = 1);
  mu_assert("parseArgs should handle huff input (in path)", strcmp(resultB->inPath, "foobar.huff") == 0);
  mu_assert("parseArgs should handle huff input (out path)", strcmp(resultB->outPath, "foobar.txt") == 0);
  mu_assert("parseArgs should handle huff input (action)", resultB->action = 2);

  mu_assert("test_parseArgs not yet implemented", 1);
}

static char *test_convert()
{
  mu_assert("test_conver not yet implemented", 0);
}

static char *test_create()
{
  mu_assert("test_sav not yet implemented", 0);
}

static char *test_huffman()
{
  log_info("test_huffman test start");
  mu_run_suite(test_parseArgs);
  mu_run_suite(test_convert);
  mu_run_suite(test_create);
  mu_assert("test_huffman not implemented", 0);
}

// TODO: Complete list of tests
static char *all_tests()
{
  mu_run_suite(test_check_testing_works);
  mu_run_suite(test_string_helpers);
  mu_run_suite(test_huff_file);
  mu_run_suite(test_character_frequency);
  mu_run_suite(test_min_heap);
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
