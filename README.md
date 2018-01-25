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
    "table": {
      characters: []
      frequencies: []
    },
    "data": "<ENCODED DATA>"
  }
```

## Instructions

### Building from Source

* TODO: ceedling

### Usage

* `./huffman <input>` - if input is a .huf file then it will decompress, otherwise it will compress the file into a new file called `<filename>-<extension>.huf`.

* `./huffman encode </path/to/input/file.txt>` - self-explanatory
* `./huffman decode </input/file.huf> </output-path>` - self-explanatory

## Tests

* TODO: run tests instructions

## Reference

[![Huffman Coding by Geeks for Geeks](https://img.youtube.com/vi/0kNXhFIEd_w/0.jpg)](https://www.youtube.com/watch?v=0kNXhFIEd_w)

[Youtube - Huffman Coding by Geeks for Geeks](https://www.youtube.com/watch?v=0kNXhFIEd_w)

[Huffman Coding on Geeks for Geeks](https://www.geeksforgeeks.org/greedy-algorithms-set-3-huffman-coding/)

## Structure

* Makefile

- [huffman.c](#huffmanc)
  - [The `.huff` File Format](#the-huff-file-format)
  - [Instructions](#instructions)
    - [Building from Source](#building-from-source)
    - [Usage](#usage)
  - [Tests](#tests)
  - [Reference](#reference)
  - [Structure](#structure)
  - [Plans](#plans)
  - [MinHeap module](#minheap-module)
    - [Binary Heaps in General](#binary-heaps-in-general)
    - [Min Heaps](#min-heaps)
  - [3rd Party Libraries, Licensing, Credits etc.](#3rd-party-libraries-licensing-credits-etc)
    - [Tools](#tools)
    - [Libraries](#libraries)

## Plans

TODO: Mindnode export

## MinHeap module

### Binary Heaps in General

* [Introduction to Binary Heaps (MaxHeaps) - YouTube](https://www.youtube.com/watch?v=WCm3TqScBM8)
  * [![Intoduction to Binary Heaps](https://img.youtube.com/vi/WCm3TqScBM8/0.jpg)](https://www.youtube.com/watch?v=WCm3TqScBM8)
* [Data Structures: Heaps - YouTube](https://www.youtube.com/watch?v=t0Cq6tVNRBA)

  * [![Title](https://img.youtube.com/vi/t0Cq6tVNRBA/0.jpg)](https://www.youtube.com/watch?v=t0Cq6tVNRBA)

* [Binary heap - Wikipedia](https://en.wikipedia.org/wiki/Binary_heap)

### Min Heaps

* [Min Heap Intro PDF](https://www.cs.cmu.edu/~tcortina/15-121sp10/Unit06B.pdf)
* [Heap | How to create a Min Heap - step by step guide - YouTube](https://www.youtube.com/watch?v=oAYtNV6vy-k&t=71s)

## 3rd Party Libraries, Licensing, Credits etc.

The following 3rd party libraries and technologies were used:

### Tools

* CEEDLING - Build system and toolchain for C [Ceedling - Throw the Switch](http://www.throwtheswitch.org/ceedling), which includes:

  * [Unity - Curiously Powerful Unit Testing in C for C](https://github.com/ThrowTheSwitch/Unity/)
  * [CMock - Automagical generation of stubs and mocks for Unity Tests](https://github.com/ThrowTheSwitch/cmock)
  * [CException - Lightweight exception handling for C](https://github.com/ThrowTheSwitch/CException)

### Libraries

* JSON: [Jansson](http://www.digip.org/jansson/)\*
* Logging: TODO: find logging
*
