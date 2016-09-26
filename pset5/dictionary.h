/**
 * dictionary.h
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Declares a dictionary's functionality.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

//structure for a trie
struct trie;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word);

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

/**
 *  Takes the word and inserts it into trie structure.  Returns false
 * if not successful at allocating into trie.  Requires:  word, current
 * index value, the level of the trie and the length of the word
 */
bool trieReadIn(char* word, int index, struct trie* level, int length);

/**  goes through the trie level by level making sure the word is in there
 * requires the word, the length of the word, current index, and the 
 * current level of the trie
 */ 
bool trieParse (char* word, int length, int index, struct trie* level);

/** clears the trie by going from the beginning to the end.  Each time it finds 
 * children it recursively calls itself and begins in that level to free memory
 */
bool trieClear(struct trie* level);

#endif // DICTIONARY_H
