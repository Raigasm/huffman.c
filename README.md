# huffman.c

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

<iframe width="1120" height="620" src="https://www.youtube.com/embed/0kNXhFIEd_w" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

[Youtube - Huffman Coding by Geeks for Geeks](https://www.youtube.com/watch?v=0kNXhFIEd_w)

[Huffman Coding on Geeks for Geeks](https://www.geeksforgeeks.org/greedy-algorithms-set-3-huffman-coding/)

## Structure

* Makefile
- [huffman.c](#huffmanc)
  - [The `.huff` File Format](#the-huff-file-format)
  - [Instructions](#instructions)
    - [Compilation](#compilation)
    - [Usage](#usage)
  - [Tests](#tests)
  - [Reference](#reference)
  - [Structure](#structure)
  - [Plans](#plans)
  - [3rd Party Libraries, Licensing, Credits etc.](#3rd-party-libraries-licensing-credits-etc)

## Plans

* [UML diagrams etc]()
* [Tests to Write]()

## 3rd Party Libraries, Licensing, Credits etc.

The following 3rd party libraries were used:

* CEEDLING -
* JSON - [Jansson](http://www.digip.org/jansson/)
*
