#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE (26)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    char label;
    bool isEndOfWord;
} TrieNode;


struct TrieNode *createTrieNode();
struct TrieNode *search(struct TrieNode *root, const char *word);
void traverse(char prefix[], struct TrieNode *root);
void insert(struct TrieNode *root, const char *word);
void printWords(struct TrieNode *node , char prefix[]);
void printPathsRecur(struct TrieNode *node, char word[], int wordLen , char prefix[] );
void printArray(char word[], int len , char prefix[] );
