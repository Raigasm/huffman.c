# Huffman Modules


## character_frequency

### char source_characters[]

### int source_character_frequency[]

### get_frequencies(char *arr, int freq[], char *input)

### print_frequencies(char *arr, int freq[])

### count_character(char input, char *arr, int freq[])

## min-heap

### struct MinHeap

### node_create

### node_isLeaf

### node_swap

### node_add

### minHeap_minHeapify

### minHeap_build

### minHeap_create

### minHeap_getMinNode

###  minHeap_hasOnlyOne

## huffman

### huffman_main

- parseArgs

	- in: none, out: huffman_config

- convert

	- input: huffman_config

	- output: raw data for final file

	- logic:

		- TODO

- save

	- output: 0/1 success/fail

### huffman_encode

- input: data to encode  
  Output: data encoded (what type?) 

### huffman_decode

- input: encoded data (huf file)   
  Output: raw uncompressed data

### huffman_config

- in: ‘full/path/for/output.txt’

- out: ‘full/path/for/output.txt’

- action: 0/1 [encode/decode]

## .huf file format

### HUF_generate

- basic

- minified

### HUF_read

- HUF_meta

	- HUF_meta_create

		- in

			- filename

			- raw data

		- out

			- HUF_meta object
			  "filename": "lol",  
			  "extension": "txt",  
			  "size": "12804"

	- HUF_meta_delete

	- HUF_meta_serialize

		- in

			- HUF_meta object

		- out

			- meta as string

	- HUF_meta_deserialize

		- in

			- Meta as string

		- out

			- HUF_meta object

