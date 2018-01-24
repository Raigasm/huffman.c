#huffman.c

compression and decompression utilities - based on huffman encoding

uses a unique file extension: `.huff` for compressed files

## The `.huff` File Format

* minified JSON object, e.g:

```
  {
    "meta": {
      "filename": "lol",
      "extension": "txt",
      "size": "12804"
    },
    "data": "<ENCODED DATA>"
  }
```

## Instructions

### Compilation

* TODO: ceedling

### Usage

* `./huffman <input>` - if input is a .huf file then it will decompress, otherwise it will compress the file into a new file called `<filename>-<extension>.huf`.

* `./huffman encode </path/to/input/file.txt>` - self-explanatory
* `./huffman decode </input/file.huf> </output-path>` - self-explanatory

## Tests

* TODO: run tests instructions

## Reference

[https://www.geeksforgeeks.org/greedy-algorithms-set-3-huffman-coding/](Huffman Coding on Geeks for Geeks)

## Structure

* Makefile
* huffman.c
* huffman.tests.c

## Plans

* [UML diagrams etc]()
* [Tests to Write]()

## 3rd Party Libraries, Licensing, Credits etc.

The following 3rd party libraries were used:

* Testing and Building -
* JSON - [Jansson](http://www.digip.org/jansson/)
*
