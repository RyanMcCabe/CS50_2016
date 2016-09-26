/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "dictionary.h"

//sets up a struct to serve as the trie
typedef struct trie
{
    bool isWord;
    struct trie* children[27];
}trie;

//sets up a root for the first part of the trie
trie* root;

//sets up a counter to count the number of words in dictionary
int counter = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // starting position of where we are in the char
    int index = 0;
    int n = strlen(word);
    char lowerCase[LENGTH];
    
    // converts each upper case character to a lower case
    for (int i = 0; i < n; i++)
    {
        if (isalpha(word[i]) != 0)
        {
            if (isupper(word[i]) != 0)            
                lowerCase[i] = word[i] - 'A' + 'a';                
            
            else if (islower(word[i]) != 0)
                lowerCase[i] = word[i];
        }
        else
            lowerCase[i] = word[i];
    }
    
    // calling the function to find out if word is in the trie
    // passing in the pointer for the root part of the trie.
    if(trieParse(lowerCase, n, index, root) == true)
        return true;
                   
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    root = malloc(sizeof(trie));
    char word[LENGTH + 1];
    
    if (root == NULL)
        return false;
        
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
        return false;
        
    while (fscanf(fp, "%s", word) != EOF)
    {
        counter++;
        int length = strlen(word);
        if(trieReadIn(word, 0, root, length) == false)
            return false;
        
    }
    
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return counter;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    return trieClear(root);
}

/**
 *  Takes the word and inserts it into trie structure.  Returns false
 * if not successful at allocating into trie.  Requires:  word, current
 * index value, the level of the trie and the length of the word
 */
bool trieReadIn(char* word, int index, trie* level, int length)
{
    int node;  //location in the trie structure
    char letter = word[index];
    
    //determines if letter or apostrophe.  Apostrophe goes to node 26
    //letters go in 0-25
    if (isalpha(letter) != 0)
        node = letter -'a';
    
    else
        node = 26;
    
    if(index +1 == length)  //checks if we are at the end of the word
    {

        //if current level doesn't exist, creates level   
        if (level->children[node]==NULL)
            level->children[node] = malloc(sizeof(trie));
        
        level->children[node]->isWord = true;
        return true;
            
    }
    //if level exists
    else
    {
        //if  current level doesn't exist, creates new level
        if(level->children[node]==NULL)
            level->children[node]=malloc(sizeof(trie));
        
        //recursively calls function and moves to next letter
        return trieReadIn(word, index+1, level->children[node], length);
        
    }
}

/**  goes through the trie level by level making sure the word is in there
 * requires the word, the length of the word, current index, and the 
 * current level of the trie
 */ 
bool trieParse (char* word, int length, int index, trie* level)
{   
    //converts current char to a number representing a postion in the trie
    int num;
    
    if (isalpha(word[index]) != 0)
        num = word[index] - 'a';        
    else
        num = 26;
    
    //checks to see if the 
    if (index == length) 
        if(level->isWord == true)
            return true;
    
        else
            return false;
          
    else 
        if (level->children[num] == NULL)
            return false;
        else    
            return trieParse(word, length, index + 1, level->children[num]);
     
    return false;    
}

/** clears the trie by going from the beginning to the end.  Each time it finds 
 * children it recursively calls itself and begins in that level to free memory
 */
bool trieClear(trie* level)
{
    for (int i = 0; i <27; i++)
    {
        if (level->children[i]!=NULL)
            trieClear(level->children[i]);
    }
    free(level);
    return true;
}